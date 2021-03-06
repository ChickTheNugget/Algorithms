#include <bits/stdc++.h>
using namespace std;

#define ll long long
int ind[100];
int outd[100];
vector<int> adj[100];
vector<int> ans;

void dfs(int node)
{
    for (auto& edge : adj[node]){
        int t = edge;
        if (edge <= -1) continue;
        edge = -1;
        outd[node]--;
        dfs(t);
    }
    if (outd[node] == 0){
        ans.push_back(node);
        return;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
        outd[a]++;
    }
    //c start node, c1 end node
    int c = 0, c1 = 0;
    for (int i = 1; i <= n; i++){
        if (ind[i] == outd[i]) continue;
        else if (ind[i] == outd[i] + 1 and c1 == 0) c1 = i;
        else if (ind[i] + 1 == outd[i] and c == 0) c = i;
        else{
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    dfs(c);
    for (auto a : ans){
        cout << a << " ";
    }
}
