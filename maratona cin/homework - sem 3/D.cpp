#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;

void printparent(vector<int>& parent, int n)
{
    if(parent[n] == 0)
    {
        cout << parent[n]+1 << " " << n+1 << " ";
    } else
    {
        printparent(parent, parent[n]);
        cout << n+1 << " ";
    }
}


int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<int> g[n];
    for(int i =0;i<m;i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n, inf);
    queue<int> q;
    vector<int> parent(n,0);

    q.push(0);
    dist[0] = 0;
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
                parent[to] = current;
            }
        }
    }
    if(dist[n-1] != inf) 
    {
    cout << dist[n-1]+1 << "\n";
    int x = n-1;
    printparent(parent,n-1);
    } else cout << "IMPOSSIBLE\n";
}