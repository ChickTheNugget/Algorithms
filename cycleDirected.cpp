#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
#define MAXN 2505
#define ll long long 
#define ld long double 
#define ui unsigned int 
#define ull unsigned ll
 
vector<pair<int, int>> adj[MAXN];
ll dist[MAXN];
int relaxant[MAXN];
int n, m, a, b, c;
vector<int> ans;
 
void bellman_ford()
{
    //just relax everthing and at the nth iteration check if there is a cycle
    int x;
    for (int i = 1; i <= n; i++){
        x = -1;
        for (int j = 1; j <= n; j++){
            for (auto e : adj[j]){
                int u = j;
                int v = e.first;
                int d = e.second;
                if (dist[u] + d < dist[v]){
                    dist[v] = dist[u] + d;
                    relaxant[v] = u;
                    x = v;
                    if (i == n){
                        ans.push_back(v);
                    }
                }
            }
        }
    }
    if (x == -1) cout << "NO\n";
    else{
        cout << "YES\n";
        //x will be part of the cycle, just look at drawing
        for (int i = 0; i < n; i++){
            x = relaxant[x];
        }
        vector<int> cycle;
        for (auto a : ans){
            cout << a << " ";
        }
        int v = x;
        while(true){
            cycle.push_back(v);
            v = relaxant[v];
            if (v == x and cycle.size() > 1){
                cycle.push_back(v);
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        for (auto e : cycle){
            cout << e << " ";
        }
    }
 
}
 
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    bellman_ford();
 
}
 