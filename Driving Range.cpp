#include <bits/stdc++.h>
#define inf 1000000000
#define ii pair<int, int>
using namespace std;

typedef pair <long long,pair<int,int>> pli;
const int MAX_VERTICES = 1e6+15;


vector<pli> grafo[MAX_VERTICES]; //grafo
int par[MAX_VERTICES];


int find(int x)
{
    if (par[x]==x) return x;
    return find(par[par[x]]);
}

int unite(int x, int y)
{
    int pai_x = find(x);
    int pai_y = find(y);
    par[pai_y] = pai_x;
}

void init()
{
    for(int i = 0; i < MAX_VERTICES; i++)
    {
        par[i] = i;
    }
}

//adj.assign(n, vector<ii>(0));
//adj[a].push_back( ii(b, w) );
vector<int> Prim(vector< vector<ii>> adj,int s, int n)
{
    vector<int> dist;
    dist.resize(n);
    for(int i = 0; i<n; i++) dist[i] = inf;
    dist[0] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(dist[s], 0));
    ii p;
    int t, u;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        t = p.first; u = p.second;
        if(t > dist[u] ) continue;
        for(int i = 0; i<adj[u].size(); i++){
            if(dist[adj[u][i].first] >  adj[u][i].second){
                dist[adj[u][i].first] = adj[u][i].second;
                pq.push( ii(dist[adj[u][i].first], adj[u][i].first) );
            }
        }
    }
    return dist;
}



void setEdge(vector<pli>& edges, int a, int b, long long w)
{
    pli newElement;
    newElement.first = w;
    newElement.second.first = a;
    newElement.second.second = b;
    edges.push_back(newElement);
    // newElement.second.first = b;
    // newElement.second.second = a;
    // edges.push_back(newElement);
}

int main()
{
    int n,m;
    cin >> n >> m;
    while (n != 0)
    {
        vector< vector<ii>> edges;
        edges.assign(n, vector<ii>(0));
        for(int i = 0; i < m; i++)
        {
            int a,b,w;
            cin >> a >> b >> w;
            edges[a].push_back( ii(b, w));
            edges[b].push_back( ii(a, w));
            
        }
        vector<int> menoresDistancias = Prim(edges,0, n);
        int maiorPeso = 0;
        for(auto peso:menoresDistancias) 
        {
            if (peso!=inf)
            {
                if(peso > maiorPeso)
                {
                    maiorPeso = peso;
                }
            } else
            {
                maiorPeso = inf;
                cout << "IMPOSSIBLE\n";
                break;
                
            }
        }
        if (maiorPeso != 0 and maiorPeso != inf)
        {
            cout << maiorPeso << "\n";                
        }
        cin >> n >> m;
    }
    return 0;
}