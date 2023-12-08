#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    map<string, int> tab;
    int cases,v;
    string a,t;
    cin >> cases;
    while (cases--)
    {
        tab.clear();
        cin >> v;
        for(int i = 0; i < v; i++)
        {
            cin >> a >> t;
            tab[t]++;
        }
        v = 1;
        for(auto &element:tab) v = v*(element.second+1);
        cout << v-1 << "\n";
    }

}
