#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;

    map<int,bool> mp;
    int e;
    int n,m;
    while(cin >> e)
    {
        mp[1] = true;
        mp[2] = true;
        mp[3] = true;
        stack<int> stk;
        queue<int> qe;
        priority_queue<int> pq;
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
                if(stk.empty() or stk.top() != m) mp[1] = false;
                else stk.pop();
                if(qe.empty() or qe.front() != m) mp[2] = false;
                else(qe.pop());
                if(pq.empty() or pq.top()!=m) mp[3] = false;
                else pq.pop();
            }
        }
        if(mp[1] and mp[2] and mp[3]) cout << "not sure\n";
        else if(!mp[1] and !mp[2] and !mp[3]) cout << "impossible\n";
        else if(mp[1] and !mp[2] and !mp[3]) cout << "stack\n";
        else if(!mp[1] and mp[2] and !mp[3]) cout << "queue\n";
        else if(!mp[1] and !mp[2] and mp[3]) cout << "priority queue\n";
        else cout << "not sure\n"; 
    }
}
