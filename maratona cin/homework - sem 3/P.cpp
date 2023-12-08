#include <bits/stdc++.h>
using namespace std;

const int maximo = 1e5+10;
vector<int> g[maximo];

bool dfs(int v, vector<bool>& d, vector<bool>& c)
{
    d[v] = true;
    for(int u:g[v])
    {
        if(!d[u])
        {
            c[u] = !c[v];
            if(!dfs(u, d, c)) return false;
        } else if(c[v] == c[u]) return false;
    }
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<bool> d(n,false),c(n,false);
    for(int i = 0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool possible = false;
    for(int i = 0; i < n; i++)
    {
        if(!d[i]) 
        {
        possible = dfs(i,d,c);
        if(!possible) break;
        }
    } 
    if(!possible) cout << "IMPOSSIBLE\n";
    else
    {
        for(auto x:c)
        {
            if(x) cout << "2 ";
            else cout << "1 "; 
        } 
    } 
}