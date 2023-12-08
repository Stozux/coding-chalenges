#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);



const int maximo = 1e5+10;
vector<int> g[maximo];
int n,m;

void bfs(vector<bool>& vis, int u)
{
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int to:g[current])
        {
            if(vis[to]== false)
            {
                vis[to] = true;
                q.push(to);
            }
        }
    }
}




int main()
{
    fIo;
    cin >> n >> m;
    for(int i = 0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    vector<int> a;
    vector<bool> vis(n,false);
    bfs(vis, 0);
    for(int i = 0;i<vis.size();i++)
    {
        if(vis[i] == false) 
        {
            g[0].push_back(i);
            g[i].push_back(0);
            cnt++;
            a.push_back(i);
            bfs(vis,i); 
        }
    }
    cout << cnt <<"\n";
    for(auto x:a) cout << 1 << " " << x+1 << " "; 

}