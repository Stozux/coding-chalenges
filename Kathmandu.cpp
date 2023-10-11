#include <bits/stdc++.h>
using namespace std;


int main()
{
    int T,D,M,cnt;
    cin >> T >> D >> M;
    cnt = 0;
    int time;
    bool pos = false;
    for(int i = 0; i < M; i++)
    {
        cin >> time;
        if(time-cnt >= T) 
        {
        cout << "Y";
        pos = true;
        break;
        }
        else cnt = time;
    }
    if (!pos)
    {
        if(D - cnt >= T)
        {
            cout << "Y";
            pos = true;
        } else cout << "N";
    } 
    return 0;
}