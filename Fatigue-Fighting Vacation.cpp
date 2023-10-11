#include <bits/stdc++.h>
using namespace std;


int main()
{
    int D,C,R;
    cin >> D >> C >> R;
    int count = 0;
    vector<int> tiring;
    tiring.resize(C);
    for (int i = 0; i < C; i++) 
    {
        int action;
        cin >> action;
        tiring[i] = action;
    }
    for (int i = 0; i < R; i++)
    {
        int revig;
        cin >> revig;
        D+=revig;
        count++;
    }
    for (int i = 0; i < C; i++) 
    {
        if(D >= tiring[i])
        {
            D -= tiring[i];
            count++;
        } else break;
    }

    cout << count;
    return 0;
}