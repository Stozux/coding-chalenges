#include <bits/stdc++.h>
using namespace std;




int main()
{   
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> indegree(n);

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        indegree[b]++;
    }
    vector<int> topo_order;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i < n; i++) if(indegree[i] == 0) pq.push(i);

    while(!pq.empty())  
    {
        int u = pq.top();
        pq.pop();
        topo_order.push_back(u);

        for(int k:g[u])
        {
            indegree[k]--;
            if(indegree[k] == 0)
            {
                pq.push(k);
            }
        }
    }

    if(topo_order.size() == n) 
    {
        for(int i = 0; i < n;i++) 
        {
            cout << topo_order[0]+1 << " ";
            topo_order.erase(topo_order.begin());
        }
    } else cout << "IMPOSSIBLE";
}