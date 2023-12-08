#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

ll solve(ll i, ll sum1, ll sum2,vector<ll>& v)
{  
    if(i == n) return abs(sum1-sum2);
    else
    {
        ll ans1 = solve(i+1,sum1 + v[i],sum2,v);
        ll ans2 = solve(i+1, sum1,sum2+v[i], v);
        return min(ans1, ans2);
    }
}

int main()
{
    ll p;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)
    {
        cin >> p;
        v[i] = p;
    }
    ll sum1=0,sum2=0;
    ll ans = solve(0,sum1,sum2,v);
    cout << ans << "\n";
}