#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9
#define MOD 1e9 + 7
#define MAXN 1000
vector<pair<char, pair<int,int>>> directions{{'U', {1, 0}}, {'D', {-1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}};
char adj[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        vis[i][j] = true;
        q.pop();
        for (auto dir : directions){
            int new_i = i + dir.second.first;
            int new_j = j + dir.second.second;
            char d = dir.first;
            if (new_i >= 0 and new_i < n and new_j >= 0 and new_j < m){
                if (!vis[new_i][new_j]){
                    adj[new_i][new_j] = d;
                    q.push({new_i, new_j});
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> adj[i][j];
        }
    }
    bfs(0, 0);
    memset(vis, false, sizeof(vis[0][0]) * m * n);
}