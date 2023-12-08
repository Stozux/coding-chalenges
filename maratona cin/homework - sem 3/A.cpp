#include <bits/stdc++.h>
using namespace std;


int main()
{
    int r=1,c,e;
    char elem;
    while(r != 0)
    {
        cin >> r >> c >> e;
        if(r == 0) break;
        vector<char> g[r];
        vector<int> v[r];
        for(int i = 0;i<r;i++)
        {
            g[i].resize(c);
            v[i].resize(c);
        }
        r--;
        c--;
        e--;
        for(int i = 0; i <= r;i++)
        {
            for(int j = 0; j <= c;j++)
            {
                cin >> elem;
                g[i][j] = elem;
                v[i][j] = 0;
            }
        }
        int steps = 0;
        bool flag = true;
        int x = 0;
        int y = e;
        char pos;
        while(flag)
        {
            pos = g[x][y];
            if(pos == 'N')
            {
                if(x == 0)
                {
                    break;
                }
                else
                {
                    steps++;
                    if(v[x][y] != 0) 
                    {
                        flag = false;
                        break;
                    }
                    v[x][y] = steps;
                    x--;
                }
            } else if(pos == 'S')
            {
                if(x == r)
                {
                    break;
                }
                else
                {
                    steps++;
                    if(v[x][y] != 0) 
                    {
                        flag = false;
                        break;

                    }
                    v[x][y] = steps;
                    x++;
                }
            } else if(pos == 'E')
            {
                if(y == c)
                {
                    break;
                }
                else
                {
                    steps++;
                    if(v[x][y] != 0) 
                    {
                        flag = false;
                        break;

                    }
                    v[x][y] = steps;
                    y++;
                }
            } else if(pos == 'W')
            {
                if(y == 0)
                {
                    break;
                }
                else
                {
                    steps++;
                    if(v[x][y] != 0) 
                    {
                        flag = false;
                        break;

                    }
                    v[x][y] = steps;
                    y--;
                }
            }
        }
        if(flag) cout << steps+1 << " step(s) to exit\n";
        else cout << v[x][y] - 1 << " step(s) before a loop of " << steps - v[x][y]  << " step(s)\n";
        r++;
        c++;
        e++;
    }
}