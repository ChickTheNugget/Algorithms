import cv2
from datetime import datetime
from datetime import date

import telebot

import requests

today_date = date.today()
today = today_date.strftime("%d-%m-%Y-")

bot_token = '5672454905:AAEdOWMdBogDYwFpn2p3Z0iHjDzUIDM-MyU'
chat_id = '-911894127'
bot = telebot.TeleBot(bot_token)

cnt = 1
static_back = None
detection_cnt = 0
detection_delay = 50

sensivity = 12
min_change = 1000

width = 640
height = 480

now = datetime.now()
current_time = now.strftime("%H;%M")
last = now.strftime("%M")
result = cv2.VideoWriter(today + current_time + '.avi', cv2.VideoWriter_fourcc(*'MJPG'), 10, (width, height))



URL = "http://192.168.1"
CAM_ID = ".19"
PORT = ":81"

requests.get(URL + CAM_ID + "/control?var=framesize&val=8")
video = cv2.VideoCapture(URL + CAM_ID + PORT + "/stream")



_, start_frame = video.read()
start_frame = cv2.cvtColor(start_frame, cv2.COLOR_BGR2GRAY)
start_frame = cv2.GaussianBlur(start_frame, (21, 21), 0)


def send_to_telegram(frame):
	current_time = now.strftime("%H;%M")
	cv2.imwrite(today + current_time + ".jpg", frame)
	image_path = today + current_time + '.jpg'
	with open(image_path, 'rb') as f:
		bot.send_photo(chat_id, f)



	
def light_mode():
	sensivity = 7
	min_change = 600

def dark_mode():
	sensivity = 3
	min_change = 1000

light_mode()


while True:

	detection_cnt += 1
	if detection_cnt > detection_delay:
		detection_cnt = detection_delay
		
	now = datetime.now()
	current_time = now.strftime("%H;%M")
	current_second = now.strftime("%S")
	current_minute = now.strftime("%M")
	current_hour = now.strftime("%H")

	if current_hour == "12":
		today = date.today()

	if current_second == "00" and last != current_minute:
		result.release()
		last = current_minute
		result = cv2.VideoWriter(today + current_time + ".avi", cv2.VideoWriter_fourcc(*'MJPG'), 10, (640,480))

	_, frame = video.read()
	
	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	gray = cv2.GaussianBlur(gray, (21, 21), 0)

	frame = cv2.flip(frame,0)
	
	result.write(frame)

	if static_back is None:
		static_back = gray
		continue
	
	diff_frame = cv2.absdiff(gray, start_frame)
	thresh_frame = cv2.threshold(diff_frame, sensivity, 255, cv2.THRESH_BINARY)[1]
	thresh_frame = cv2.dilate(thresh_frame, None, iterations = 2)
	start_frame = gray
	
	cnts, _ = cv2.findContours(thresh_frame.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
	
	

	for contour in cnts:
		(x, y, w, h) = cv2.boundingRect(contour)
		if cv2.contourArea(contour) < min_change or h <= 20 or w // h >= 3:
			continue

		elif detection_cnt > detection_delay - 5:
			send_to_telegram(frame)
			detection_cnt = 0
			#break
		#to be removed in final code
		cnt += 1
		cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 3)
		print(f"{w}-{h}")


	# cv2.imshow("Gray Frame", gray)
	# cv2.imshow("Difference Frame", diff_frame)
	cv2.imshow("Color Frame", frame)
	key = cv2.waitKey(1)


bot.polling()
result.release()
video.release()
cv2.destroyAllWindows()
