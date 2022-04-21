#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9
#define MOD 1e9 + 7
#define MAXN 100005
vector<pair<int, int>> adj[MAXN];
vector<int> dist(MAXN, INF);
bool vis[MAXN];
int n, m;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (auto edge : adj[node]){
            int new_node = edge.first;
            int new_weight = edge.second;
            if (new_weight + weight < dist[new_node]){
                dist[new_node] = new_weight + weight;
                pq.push({dist[new_node], new_node});
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
    int a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    memset(vis, false, sizeof(vis));
}