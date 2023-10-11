#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    long long n,k,x;
    for (int  i = 0; i < cases; i++)
    {
        cin >> n >> k >> x;
        if(x >= ((k*(k+1))/2) and x <= ((n*(n+1)-(n-k)*(n-k+1))/2))
        {
            cout << "YES\n";
        } else cout << "NO\n";
    }
    return 0;
}