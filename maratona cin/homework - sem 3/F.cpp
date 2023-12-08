#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;


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
    vector<int> dist2(n, inf);
    queue<int> q2;

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
            }
        }
    }
    int maior_indice = 0;
    int maior = dist[0];
    for(int i = 1;i<dist.size();i++)
    {
        if(dist[i] > maior and dist[i]!=inf) 
        {
        maior_indice = i;
        maior = dist[i];
        }
    }

    q2.push(maior_indice);
    dist2[maior_indice] = 0;
    while (!q2.empty())
    {
        int current = q2.front();
        q2.pop();
        for(int to:g[current])
        {
            if(dist2[to] > dist2[current]+1)
            {
                dist2[to] = dist2[current]+1;
                q2.push(to);
            }
        }
    }
    maior = dist2[0];
    for(int i = 1;i<dist2.size();i++)
    {
        if(dist2[i] > maior) maior = dist2[i];
    }
    if(maior == inf) cout << "=[\n";
    else cout << "=] " << maior << "\n";
}

