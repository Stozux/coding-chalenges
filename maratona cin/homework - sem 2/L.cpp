#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);






int main()
{
    fIo;
    int n,x,a;
    cin >> n >> x;
    vector<int> arr(n);
    map<int,int> tab;
    for(int i = 0; i < n; i++)
    {  
        cin >> a;
        arr[i] = a;
    }   
    bool pos = false;
    for(int i = 0; i < n; i++)
    {
        if(tab.count(x-arr[i]))
        {
            cout << i+1 << " " << tab[x-arr[i]]+1 << "\n";
            pos = true;
            break;
        }
        else tab[arr[i]] = i;
    }
    if(!pos) cout << "IMPOSSIBLE\n";
}