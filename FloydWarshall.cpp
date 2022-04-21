#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9 + 7
#define MOD 1e9 + 7
#define MAXN 1000
vector<vector<int>> dist(MAXN, vector<int>(MAXN, INF));
int n, m;

void floyd()
{
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (i == j) dist[i][j] = 0;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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
    int a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    floyd();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
}