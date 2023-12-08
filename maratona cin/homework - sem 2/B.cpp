#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

bool check(vector<int>& arr, int x, int m)
{
    int cows = 1;
    int dist = arr[0];
    for(int i =1;i<arr.size();i++)
    {
        if(cows >= x) return true;
        if(arr[i] - dist >= m)
        {
            cows++;
            dist = arr[i];
        }
    }
    if(cows >= x) return true;
    return false;
}


int bs(vector<int>& arr, int x)
{
    int l = 0;
    int r = 1e9+20;
    int best = r;
    while (l<r)
    {
        int m = (l+r)/2;
        if(check(arr,x,m))
        {
            best = m;
            l = m+1;
        } else r = m;
    }
    return best;
}


int main()
{
    fIo;
    int cases,n,c,s;
    cin >> cases;
    while (cases--)
    {
        cin >> n >> c;
        vector<int> posit(n); 
        for(int& x:posit) cin >> x;   
        sort(posit.begin(), posit.end());
        int ans = bs(posit,c);
        cout << ans << "\n";
    }
}