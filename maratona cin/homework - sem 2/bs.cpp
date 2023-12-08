#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>& arr, int t)
{
    int l = 0;
    int r = arr.size();
    int meio;
    while(l<=r)
    {
        meio = (l+r)/2;
        if(arr[meio] == t) return meio;
        else if (arr[meio] < t) l = meio + 1;
        else if (arr[meio] > t) r = meio - 1;
    }
    return -1;
}





int main()
{
    int n,m,num;
    cin >> n >> m;
    vector<int> arr;
    for(int i = 0; i < n;i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    for(int i = 0; i<m;i++)
    {
        cin >> num;
        int ans = bs(arr,num);
        if(ans != -1) cout << "YES\n";
        else cout << "NO\n";
    }
}