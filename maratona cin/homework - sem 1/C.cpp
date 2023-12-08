#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    int cases,q,e,cnt;
    vector<int> s;
    long long sum;
    cin >> cases;
    while (cases--)
    {
        s.clear();
        sum = 0;
        cnt = 1;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cin >> e;
            s.push_back(e);
        }
        for(int i = 0; i < q-1; i++)
        {
            if(s[i] > sum and sum+s[i] < s[i+1])
            {
                sum+=s[i];
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
