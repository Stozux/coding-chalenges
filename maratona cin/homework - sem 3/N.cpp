#include<bits/stdc++.h>
using namespace std;

const int maximo = 1e5+10;
vector<int> g[maximo];

int n,m;



void bfs()
{
    priority_queue<int,vector<int>,greater<int>> q;
    vector<bool> vis(n,false);

    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int current = q.top();
        q.pop();
        cout << current+1 << " ";

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
    bfs();
}