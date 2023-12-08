#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;





bool check(vector<int>& arr,ll m, ll x)
{
    int cnt = 1;
    ll sum = 0;
    for(auto &e:arr)
    {
        if(e>m or cnt>x) return false;
        if(e+sum > m)
        {
            cnt++;
            sum= e;
        }
        else sum+=e;
    }
    if(cnt<=x) return true;
    else return false;
}

int bs(vector<int>& arr, ll x)
{
    ll l = 1;
    ll r =  2e5 * 1e9;
    ll best = r;
    while (l < r)
    {
        ll mid = (l+r)/2;
        if(check(arr,mid,x))
        {
            best = mid;
            r = mid;
        } else
        {
            l = mid+1;
        }
    }
    return best;
}




int main()
{
    fIo;
    int n,k,x;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n;i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    ll ans = bs(arr,k);
    cout << ans << "\n";
}