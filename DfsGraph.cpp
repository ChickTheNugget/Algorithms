#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9
#define MOD 1e9 + 7
#define MAXN 100005
vector<int> adj[MAXN];
bool vis[MAXN];
int n, m;

void dfs(int node)
{
    vis[node] = true;
    for (auto edge : adj[node]){
        if (!vis[edge]){
            cout << edge << " ";
            dfs(edge);
        }
    }
    //backtrack
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
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i);
        }
    }
    memset(vis, false, sizeof(vis));
}