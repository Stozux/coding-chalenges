#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
const int maximo = 2*1e3;
vector<int> g[maximo];


int bfs(int u, vector<int>& dist)
{
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int to:g[current])
        {
            if(dist[to] > dist[current]+1)
            {
                dist[to] = dist[current]+1;
                q.push(to);
            }
        }
    }
    int x = 0;
    for(auto e:dist) if(e > x) x = e;
    return x;
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i =0;i<m;i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int maior1 = 0;
    for(int i = 0;i<n;i++)
    {
        vector<int> dist(n,inf);
        int maior2 = bfs(i,dist);
        if(maior2 > maior1) maior1 = maior2;
    }
    if(maior1 == inf) cout << "=[\n";
    else
    {
        cout << "=] " <<maior1 << "\n";
    }
}

