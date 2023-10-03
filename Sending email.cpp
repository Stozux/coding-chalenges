#include <bits/stdc++.h>
#define inf 1000000000
#define ii pair<int, int>
using namespace std;

//adj.assign(n, vector<ii>(0));


vector<int> Dijkstra(vector< vector<ii>> adj,int s, int n)
{
    vector<int> dist;
    dist.resize(n);
    for(int i = 0; i<n; i++) dist[i] = inf;
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push( ii(dist[s], s) );
    ii p;
    int t, u;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        t = p.first; u = p.second;
        if(t > dist[u] ) continue;
        for(int i = 0; i<adj[u].size(); i++){
            if(dist[adj[u][i].first] > dist[u] + adj[u][i].second){
                dist[adj[u][i].first] = dist[u] + adj[u][i].second;
                pq.push( ii(dist[adj[u][i].first], adj[u][i].first) );
            }
        }
    }
    return dist;
}


int main()
{
    vector< vector<ii>> adj;
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        adj.assign(n, vector<ii>(0));
        for (int i = 0; i < m; i++)
        {
            int a,b,w;
            cin >> a >> b >> w;
            adj[a].push_back( ii(b, w) );
            adj[b].push_back( ii(a, w) );
        }
        vector<int> dist = Dijkstra(adj,s,n);
        if (dist[t] == inf) 
        {
            cout << "Case #" << i+1 << ": unreachable\n";
        }else {
            cout << "Case #" << i+1 << ": " << dist[t] << "\n";
        }
    }
}