// tle sol
// kinda like digit dp
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
map<int,int> allsub(int x,map<int, int>mp) {
	int x_ = x;
	vector<int>ar;
	while (x_) {
		ar.push_back(x_%10);
		x_/=10;
	}
	reverse(ar.begin(),ar.end());
	for(int i=0;i<ar.size();i++){
		int num=0;
		for(int j=i;j<ar.size();j++){
			num=num*10 + ar[j];
			mp[num] = 1;
		}
	}
	return mp;
}
int go(int i, int l, map<int, int>&mp) {
	if (i < l)return 0;
	if (mp[i])return 0;
	int ret = go(i - 1, l, mp);

	ret = max(ret, go(i - 1, l, allsub(i,mp)) + 1);
	return ret;
}
void solve() {
	int l, r;
	cin >> l >> r;
	map<int, int>mp;
	cout << go(r, l, mp) << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}