#include <bits/stdc++.h>
using namespace std;
vector<int> t;
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


void debugvec(vector<int>& v)
{
    for(auto k:v) cout << k << " ";
    cout << "\n";
}


void rec(vector<int>& sum, int i, int soma, int n)
{
    if(i == n) {sum.push_back(soma); return;}
    else{
        rec(sum,i+1,soma+t[i],n);
        rec(sum,i+1,soma,n);
    }
}


int32_t main()
{
    io;
    int n,x,e;
    cin >> n >> x;
    vector<int>sum1,sum2;
    for(int i =0;i<n/2;i++)
    {
        cin >> e;
        t.push_back(e);
    }
    int soma=0;
    rec(sum1,0,soma,t.size());
    t.clear();
    for(int i =n/2;i<n;i++)
    {
        cin >> e;
        t.push_back(e);
    }
    soma = 0;
    rec(sum2,0,soma,t.size());
    sort(sum1.begin(),sum1.end());
    sort(sum2.begin(),sum2.end());
    int cnt= 0;
    // debugvec(sum1);
    // debugvec(sum2);
    for (int a : sum1){
    cnt += upper_bound(begin(sum2),end(sum2), x-a) - lower_bound(begin(sum2),end(sum2), x-a);
}
    cout << cnt << "\n";
}   