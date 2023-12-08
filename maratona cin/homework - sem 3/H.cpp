#include <bits/stdc++.h>
using namespace std;


const int inf = 1e8;



int main()
{
    freopen("jumping.in", "r", stdin);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<int> dist(n,inf);
        vector<int> g[n];
        int a;
        for(int i = 0;i<n;i++)
        {
            cin >> a;
            if(i-a >= 0) g[i-a].push_back(i);
            if(i+a < n) g[i+a].push_back(i);
        }
        queue<int> q;
        q.push(n-1);
        dist[n-1] = 0;
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
        for(auto x:dist)
        {
            if(x == inf) cout <<-1 << "\n";
            else(cout << x << "\n");
        }
    }   
}