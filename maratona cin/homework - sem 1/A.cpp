#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    map<set<int>,int> tab;
    set<int> mat;
    int cases,v,cnt1,cnt2;
    cases = -1;
    while(cases != 0)
    {
        cin >> cases;
        if(cases == 0) break;
        cnt1 = 0;
        cnt2 = 1;
        tab.clear();
        mat.clear();
        for(int i = 0; i < cases; i++)
        {
            mat.clear();
            for(int j = 0; j < 5; j++)
            {
                cin >> v;
                mat.insert(v);
            }
            tab[mat] ++;
            if(tab[mat] == cnt1) cnt2++;
            else if(tab[mat] > cnt1) 
            {
                cnt1++;
                cnt2 = 1;
            }
        }
        cout << cnt1*cnt2 << "\n";
    }
    return 0;
}
