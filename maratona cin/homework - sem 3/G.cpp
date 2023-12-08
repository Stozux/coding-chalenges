#include<bits/stdc++.h>
using namespace std;
#define pli pair<int,int>
const int ms = 1000;

int grid[ms][ms];
bool vis[ms][ms];
int n,m;

bool inRange(int x,int y)
{
    return x >= 0 && x < n && y>=0 && y<m;
}

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(int u,int v)
{
    int maximo = 0;
    queue<pli> q;
    vis[u][v] = true;
    q.push({u,v});
    maximo += grid[u][v];
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int ax = x + dx[i], ay = y+dy[i];
                if(inRange(ax,ay) and !vis[ax][ay] and grid[ax][ay]!=0)
                {
                    vis[ax][ay] = true;
                    q.push({ax,ay});
                    maximo += grid[ax][ay];

                }
            }
        }
    }
    return maximo;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        cin >> n >> m;
        int e;
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                cin >> e;
                grid[i][j] = e;
                vis[i][j] = false;
            }
        }
        int maximo = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j] != 0)
                {
                    int result = bfs(i,j);
                    if(result > maximo) maximo = result;
                }
            }
        }
        cout << maximo << "\n";
    }
}