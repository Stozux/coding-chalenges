#include<bits/stdc++.h>
using namespace std;
#define pli pair<int,int>
const int ms = 100;

char grid[ms][ms];
bool vis[ms][ms];
int n,m;

bool inRange(int x,int y)
{
    return x >= 0 && x < n && y>=0 && y<m;
}

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int u,int v)
{
    queue<pli> q;
    vis[u][v] = true;
    q.push({u,v});
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
                if(inRange(ax,ay) and !vis[ax][ay] and grid[ax][ay]=='#')
                {
                    vis[ax][ay] = true;
                    q.push({ax,ay});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    char e;
    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin >> e;
            grid[i][j] = e;
        }
    }
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(!vis[i][j] and grid[i][j] == '#')
            {
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}