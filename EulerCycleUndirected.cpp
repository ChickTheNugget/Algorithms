#include <bits/stdc++.h>
using namespace std;

#define ll long long
int outd[100];
vector<int> adj[100];
vector<int> ans;
bool vis[100];
int n, m;
//circuit if every vertex has even degree
//path if all even or 2 odd degree
int dfscheck(int node, int a, int b, int cnt)
{
    vis[node] = true;
    for (auto edge : adj[node]){
        if (!vis[edge]){
            if (a == node and b == edge) continue;
            if (b == node and a == edge) continue;
            cnt += dfscheck(edge, a, b, cnt);
        }
    }
    return cnt + 1;
}

bool isValid(int node, int edge, int a, int b)
{
    if (outd[node] == 1){
        return true;
    }
    memset(vis, false, sizeof(vis));
    int c = dfscheck(node, -1, -1, 0);;
    memset(vis, false, sizeof(vis));
    int c1 = dfscheck(node, a, b, 0);
    //cout << endl;
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
        else{
            //cout << "NO " << node << " " << edge << endl;
        }
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
        return 0;
    }
    if (odd == 0) cout << "only circuit possible\n";
    else cout << "only path possible\n";
    if (nodeodd != -1) node = nodeodd;
    // dfs the graph
    // if only edge then yes
    // else if bridge no go next
    node = 5;
    ans.push_back(node);
    dfs(node, -1);
    for (auto a : ans){
        cout << a << " ";
    }
}
