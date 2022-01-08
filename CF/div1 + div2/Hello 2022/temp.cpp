#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 998244353;
string s;
vector<int>cnt(30), ar;
ll go(int idx, int tot) {
	if (idx == ar.size()) {
		if (tot == 0)return 1;
		return 0;
	}
	ll res = 0;
	for (int i = 0; i <= ar[idx]; i++) {
		res += go(idx + 1, tot - i) % MOD;
	}
	return res;
}
int  main ()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (cnt[i])
			ar.push_back(cnt[i]);
	}
	ll res = 0;
	for (int i = 1; i <= s.size(); i++) {
		res += go(0, i);
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}