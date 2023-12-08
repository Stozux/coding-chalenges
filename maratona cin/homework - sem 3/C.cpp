#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

void dfs(vector<int> g[], vector<int>& vis, int cnt, int u, int max, int& cam)
{   
    if(vis[u] == -1) cnt++;
    else(cnt = 0);
    vis[u] = 1;
    if(cnt > max) 
    {
        cnt--;
        return;
    }
    if(g[u].size()==1 and u!=0) cam++;
    for(int v:g[u])
    {
        if(vis[v] != 1) dfs(g,vis,cnt,v,max,cam);
    }
}


int main()
{
    fIo;
    int n,max; 
    cin >> n >> max;
    vector<int> g[n];
    vector<int> visted(n);
    int e;
    for(int i = 0;i<n;i++)
    {
        cin >> e;
        if(e == 1) visted[i] = -1;
        else visted[i] = 0;
    }
    for(int i = 0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    int cam = 0;
    dfs(g,visted,cnt,0,max,cam);
    cout << cam << "\n";
}