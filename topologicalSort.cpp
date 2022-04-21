#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9
#define MOD 1e9 + 7
#define MAXN 1000

vector<int> adj[MAXN];
bool vis[MAXN];
stack<int> st;
vector<int> ans;
int n, m;

void topological(int node, int par)
{
    vis[node] = true;
    for (auto a : adj[node]){
        if (!vis[a] and a != par){
            topological(a, par);
        }
    }
    st.push(node);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    topological(1, -1);
    while(!st.empty()){
        ans.push_back(st.top());
        cout << st.top() << " ";
        st.pop();
    }
    
}