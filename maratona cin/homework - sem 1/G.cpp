#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);


bool comp(string x, string y)
{
    if(x + y < y + x) return  true;
        else return false;
}

int main()
{
    fIo;
    vector<string> fila;
    string w;
    string y,x;
    int cases;
    cin >> cases;
    while (cases--)
    {  
       cin >> w;
       fila.push_back(w);     
    }
    sort(fila.begin(),fila.end(),comp);
    for(auto element:fila) cout << element;
}

