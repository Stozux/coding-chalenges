#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,k;
	cin >> n>> k;
	string s;
	cin >> s;
	if (k < n)
	{
		vector<int> cnt;
		cnt.resize(26);
		for (auto c : s) cnt[c-'a']+=1;

		int pos = 26;
	for(int i =0; i < 26; i++)
	{
		if(cnt[i] <= k) k-=cnt[i];
		else
		{
		pos = i; 
		break;
		}
	}
		string res;
		int rem = k;
		for(int i = 0; i < n; i++)
		{
			if(s[i] - 'a' > pos and (s[i]- 'a' == pos or rem == 0)) res += s[i];
			else if(s[i] - 'a' == pos){
				if(rem > 0) rem--;
				else res += s[i];
			}
		}
		cout << res;

	}
	return 0;
}