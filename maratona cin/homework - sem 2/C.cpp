#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);


bool check(vector<long long>& arr, long long y,int t)
{
    long long soma = 0;
    for(auto x:arr) 
    {
        soma+=(y/x);
        if(soma >= t) return soma;
    }
    return soma >= t;
}



void solve(vector<long long>& arr,int t)
{
    long long l = 1;
    long long r = 1e18+10;
    long long best = r;
    while (l<r)
    {
        long long mid = l + (r-l)/2;
        if(check(arr,mid,t))
        {
            best = mid;
            r = mid;
        } else
        {
            l = mid+1;
        }
    }
    cout << best << "\n";
}


int main()
{
    int n,t,k;
    vector<long long> times;
    cin >> n >> t;
    for(int i = 0;i<n;i++)
    {
        cin >> k;
        times.push_back(k);
    } 
    solve(times,t);
}