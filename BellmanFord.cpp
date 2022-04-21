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

void bellman(int start)
{
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++){
        for (int node = 1; node <= n; node++){
            for (auto edge : adj[node]){
                int nd = edge.first;
                int weight = edge.second;
                dist[edge.first] = min(dist[nd], dist[node] + weight);
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
    bellman(1);
    for (int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    memset(vis, false, sizeof(vis));
}