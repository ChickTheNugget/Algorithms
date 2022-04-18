#include <bits/stdc++.h>
using namespace std;

#define ll long long
int outd[100];
vector<int> adj[100];
vector<int> ans;
bool vis[100];
int cnt = 0;
int n, m;

int dfscheck(int node, int a, int b)
{
    vis[node] = true;
    for (auto edge : adj[node]){
        if (!vis[edge] and edge != -1){
            if (a == node and b == edge) continue;
            if (b == node and a == edge) continue;
            cnt += dfscheck(edge, a, b);
        }
    }
    return cnt;
}

bool isValid(int node, int edge, int a, int b)
{
    if (outd[node] == 1){
        return true;
    }
    memset(vis, false, sizeof(vis));
    dfscheck(node, -1, -1);
    int c = cnt;
    cnt = 0;
    memset(vis, false, sizeof(vis));
    dfscheck(node, a, b);
    int c1 = cnt;
    cnt = 0;
    // cout << c << " " << c1 << endl;
    if (c == c1) return true;
    else return false;
}

void remove_edge(int node, int edge)
{
    vector<int>::iterator it;
    it = find(adj[node].begin(), adj[node].end(), edge);
    *it = -1;
    it = find(adj[edge].begin(), adj[edge].end(), node);
    *it = -1;

}

void dfs(int node, int par)
{   
    for (auto edge : adj[node]){
        //node - edge is only one
        if (edge == -1 or edge == par) continue;
        if (isValid(node, edge, node, edge)){
            ans.push_back(edge);
            // cout << "YES " << node << " " << edge << endl;
            outd[node]--;
            outd[edge]--;
            remove_edge(node, edge);
            dfs(edge, node);
        }
        // else{
        //     cout << "NO " << node << " " << edge << endl;
        // }
    }
    
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
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
        outd[b]++;
        outd[a]++;
    }
    int odd = 0;
    int even = 0;
    int node = 1;
    int nodeodd = -1;
    for (int i = 1; i <= n; i++){
        if (outd[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
            nodeodd = i;
        }
        if (outd[i] > outd[node]){
            node = i;
        }
    }
    if (odd > 3 or odd == 1){
        cout << "IMPOSSIBLE";
    }
    if (odd == 0) cout << "only path possible\n";
    if (nodeodd != -1) node = nodeodd;
    //cout << node << endl;
    //dfs the graph
    // if only edge then yes
    // else if bridge no go next
    ans.push_back(node);
    dfs(node, -1);
    for (auto a : ans){
        cout << a << " ";
    }
}
