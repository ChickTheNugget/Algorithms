#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9
#define MOD 1e9 + 7
#define MAXN 1000

int n, m, a, b;
vector<int> adj[MAXN];
int ind[MAXN];
vector<int> ans;


void topological(int node, int par)
{
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (ind[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto edge : adj[node]){
            ind[edge]--;
            if (ind[edge] == 0) q.push(edge);
        }
    }
    if (ans.size() != n) cout << "IMPOSSIBLE";
    else{
        for (auto e : ans) cout << e << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }
    topological(1, -1);
    
}