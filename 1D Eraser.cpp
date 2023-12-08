#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t,n,k;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int cnt = 0;
        cin >> n >> k >> s;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'B')
            {
                cnt++;
                int f = min(k,n-i);
                for(int j = 0; j < f; j++)
                {
                    s[i+j] == 'W';
                }
                i += f-1;
            }
        }
        cout << cnt << "\n";
    }


    return 0;
}