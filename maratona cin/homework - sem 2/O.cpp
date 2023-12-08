#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);



double dist(pair<int,int> x, pair<int,int> y)
{
    double dist1 = abs(x.first-y.first);
    double dist2 = abs(x.second-y.second);
    return sqrt(dist1*dist1 + dist2*dist2);

}



bool check(pair<int,int> a, pair<int,int> b, pair<int,int> p, double r)
{
    pair<int,int> comeco;
    comeco.first = 0;
    comeco.second = 0;
    if(dist(a,comeco) <= r)
    {
        if(dist(a,p) <= r)
        {
            return true;
        }
        else if(dist(b,p) <= r)
        {
            if(dist(b,a) <= 2*r)
            {
                return true;
            }
        }
    } else if(dist(b,comeco) <= r)
    {
        if(dist(b,p) <= r) return true;
        else if(dist(a,p) <= r)
        {
            if(dist(a,b) <= 2*r) return true;
        }
    } return false;
}



void solve(pair<int,int> a, pair<int,int> b, pair<int,int> p)
{
    const double eps = 1e-9;
    double l = 0, r = 1e7+10;
    double best = r;
    while(r-l > eps)
        {
        double mid = l + (r-l)/2;
        if(check(a,b,p,mid))
        {
            best = min(best,mid);
            r = mid;
        } else
        {
            l = mid+eps;
        }
    }
    cout << setprecision(10) << fixed;
    cout << best << "\n";
}


int main()
{
    int cases,e;
    pair<int,int> a,b,p;
    cin >> cases;
    while (cases--)
    {
        cin >> e;
        p.first = e;
        cin >> e;
        p.second = e;
        cin >> e;
        a.first = e;
        cin >> e;
        a.second = e;
        cin >> e;
        b.first = e;
        cin >> e;
        b.second = e;
        solve(a,b,p);
    }
}