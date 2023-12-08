#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MXN =510; 
const int INF = 1e15;





int32_t main()
{
    int adj[MXN][MXN];
    for(int i = 0;i<MXN;i++)
    {
        for(int j =0;j<MXN;j++)
        {
            if(i == j)
            {
                adj[i][j] = 0;
            }else adj[i][j] = INF;
        }
    }
    int n,m,q,a,b,c;
    cin >> n >>m >> q;
    for(int i =0;i<m;i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        c = min(c,adj[a][b]);
        adj[a][b]=c;
        adj[b][a]=c;
    }
    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int d1 = adj[i][j];
                int d2 = adj[i][k] + adj[j][k];
                adj[i][j] = min(d1, d2);
            }
        }
    }
    for(int i = 0;i<q;i++)
    {
        cin >> a >> b;
        a--;
        b--;
        if(adj[a][b] != INF) cout << adj[a][b] << "\n";
        else cout << -1 << "\n";
    }
}