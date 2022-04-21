#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9
#define MOD 1e9 + 7
#define MAXN 1000
int n, m;
int timer = 0;
vector<int> adj[MAXN];
int intime[MAXN];
int lowtime[MAXN];
bool vis[MAXN];

void dfs(int node, int par)
{
    vis[node] = 1;
    intime[node] = lowtime[node] = timer++;
    for (auto edge : adj[node]){
        if (edge == par) continue;
        if (vis[edge]){
            //update lowtime
            lowtime[node] = min(lowtime[node], intime[edge]);
            continue;
        }
        else{
            dfs(edge, node);
            lowtime[node] = min(lowtime[node], lowtime[edge]);
            if (lowtime[edge] > intime[node]){
                cout << edge << "-" << node << endl;
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
    //detect bridges
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, -1);
        }
    }
    // for (int i = 1; i < 100; i++){
    //     cout << intime[i] << " ";
    // }
    // cout << "\n\n";
    // for (int i = 1; i < 100; i++){
    //     cout << lowtime[i] << " ";
    // }

}