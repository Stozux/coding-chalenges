#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    int cases,p1,p2;
    vector<pair<int,int>> h;
    stack<pair<int,int>> tv1,tv2;
    cin >> cases;
    int a = cases;
    bool pos = true;
    while (a--)
    {   
        cin >> p1 >> p2;
        h.emplace_back(p1,p2);
    }
    sort(h.begin(), h.end());
    for(int i =0;i<h.size();i++)
    {
        if(tv1.empty()) tv1.push(h[i]);
        else if(!tv1.empty() and h[i].first > tv1.top().second) tv1.push(h[i]);
        else if(tv2.empty()) tv2.push(h[i]);
        else if(!tv2.empty() and h[i].first > tv2.top().second) tv2.push(h[i]);
        else 
        {
            pos = false;
            break;  
        }
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
}

