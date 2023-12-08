#include <bits/stdc++.h>
using namespace std;



	
	
int bs(vector<int>& arr, int x)
{
	int l = 0;
	int r = arr.size();
	while (l < r)
	{
		int mid = (l+r)/2;
		if(arr[mid] == x) return mid;
		else if (arr[mid] > x) r = mid;
		else if (arr[mid] < x) l = mid+1;
	}
	return -1;
}






int main()
{
	int n,m,e;
	cin >> n >> m;
	vector<int> arr(n);
	for(int i=0;i<n;i++) 
	{
		cin >> e;
		arr[i] = e;
	} 
	for(int i=0;i<m;i++)
	{
		cin >> e;
		if(bs(arr,e) != -1) cout << "YES\n";
		else cout << "NO\n";
	}
}