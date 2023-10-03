#include <bits/stdc++.h>
#define inf 1000000000
#define ii pair<int, int>
using namespace std;

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
    int n,k;
    cin >> n >> k;
    adj.assign(n, vector<ii>(0));
    vector<int> pesos;
    for(int i = 0; i < n; i++)
    {
        int peso;
        cin >> peso;
        pesos.push_back(peso);
    }
    for(int i = 0; i < n; i++)
    {
        int arestas = min(n-i,k);
        for(int j = 1; j <= arestas; j++)
        {
            adj[i].push_back(ii(i+j,abs(pesos[i+j]-pesos[i])));
        }
    }
    vector<int> dist = Dijkstra(adj,0,n);
    cout<<dist[n-1]<<"\n";
    return 0;
}