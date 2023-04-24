#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
#define MAXN 100005
#define ll long long 
#define ld long double 
#define ui unsigned int 
#define ull unsigned ll
int INF = 1e9 + 7;
int n, m, a, b, c;
vector<vector<int>> v(MAXN);
vector<vector<int>> rv(MAXN);
int vis[MAXN];
int vis1[MAXN];
stack<int> s;

void dfs(int node, int par)
{
    vis[node] = 1;
    for (auto edge : v[node]){
        if (vis[edge] and edge != par) continue;
        dfs(edge, node);   
    }
    s.push(node);
}

void connected(int node)
{
    cout << node << " ";
    vis1[node] = 1;
    for (auto edge : rv[node]){
        if (!vis1[edge]){
            connected(edge);
        }
    }
    
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        rv[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i, -1);
        }
    }
    while(!s.empty()){
        int a1 = s.top();
        s.pop();
        if (vis1[a1]) continue;
        connected(a1);
        cout << endl;
        
    }

}
 
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}