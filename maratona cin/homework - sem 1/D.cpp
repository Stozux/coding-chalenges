#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    stack<int> stk;
    queue<int> qe;
    priority_queue<int> pq;
    map<int,bool> mp;
    int e;
    int n,m;
    while(cin >> e)
    {
        mp[1] = true;
        mp[2] = true;
        mp[3] = true;
        while (e--)
        {
            cin >> n >> m;
            if(n == 1)
            {
                stk.push(m);
                qe.push(m);
                pq.push(m);
            } else if(n == 2)
            {
                if(stk.top() != m) mp[1] = false;

            }
        }
        
    }


}
