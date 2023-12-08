#include <bits/stdc++.h>
#define int long long
using namespace std;
using iii = tuple<int,int,int>;

struct DSU
{
    int n;
    vector<int> root,sz;
    DSU(int n)
    {
        this->n = n;
        root.resize(n);
        sz.assign(n,1);

        for(int i = 0;i<n;i++)
        {
            root[i] = i;
        }
    }
    int find(int a)
    {
        if(a == root[a]) return a;
        return root[a] = find(root[a]);
    }
    void join(int a,int b)
    {
        a =find(a);
        b =find(b);
        if(a != b)
        {
            if(sz[a]< sz[b])
            {
                root[b] =a;
            } else root[a] = b;
            sz[a] += sz[b];
            sz[b]= sz[a];
        }
    }
};


int kruskal(int n,vector<iii>  &edges)
{
    DSU dsu(n);
    int mst_cost = 0,comp=0;
    sort(edges.begin(),edges.end());
    for(auto [w,u,v]:edges)
    {
        if(dsu.find(u)!= dsu.find(v))
        {
            comp++;
            mst_cost+=w;
            dsu.join(u,v);
        }
    }
    if(comp != n-1) return -1;
    return mst_cost;
}


int32_t main()
{
    int n,m,a,b,c;
    cin >> n >> m;
    vector<iii> edges;
    for(int i = 0;i<m;i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back({c,a,b});
    }
    int ans = kruskal(n,edges);
    if(ans != -1) cout << ans << "\n";
    else(cout << "IMPOSSIBLE\n");
}