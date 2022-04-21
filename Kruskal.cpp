#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9 + 7
#define MOD 1e9 + 7
#define MAXN 100005
vector<pair<int, pair<int, int>>> adj(MAXN);
int par[MAXN];
int n, m;
int s = 0;

int parent(int node)
{
    while(node != par[node]){
        node = par[node];
        par[node] = par[parent(node)];
    }
    return node;
}

void merge(int a, int b)
{
    par[parent(a)] = par[parent(b)];
}

//merge by rank
// int merge(int a, int b){
//     a = parent(a);
//     b = parent(b);
//     if (comp[a] < comp[b]) swap(a, b);
//     par[b] = a;
//     comp[a] += comp[b];
//     return comp[a];
// }

void kruskal()
{
    for (auto e : adj){
        int a = e.second.first;
        int b = e.second.second;
        int c = e.first;
        if (parent(a) != parent(b)){
            cout << a << " " << b << endl;
            s += c;
            merge(a, b);
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
        par[i] = i;
        cin >> a >> b >> c;
        adj[i] = {c, {a, b}};
    }
    sort(adj.begin(), adj.end());
    kruskal();
    cout << s;
}