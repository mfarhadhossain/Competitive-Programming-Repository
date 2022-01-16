#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 100 + 10, MOD = 1e9 + 7;
int n, h[MAX], k[MAX];
ll sum(ll x) {
	return x * (x + 1) / 2;
}
map< pair<int, ll> , ll > dp;
ll go(int idx, ll curr) {
	if (idx > n) {
		return 0;
	}
	if (dp[ {idx, curr}]) {
		return dp[ {idx, curr}];
	}
	ll ret = 1e18;


	if (h[idx] == 1) {
		ret = 1 + go(idx + 1, 1);
	}
	if (curr == 0) {
		ret = min(ret, sum(h[idx]) + go(idx + 1, h[idx]));
	}
	ll prev = k[idx] - h[idx] + 1;

	if (prev > k[idx - 1]) {
		ret = min(ret, sum(h[idx]) + go(idx + 1, h[idx]));
	}
	else {
		ll df = k[idx] - k[idx - 1];
		if (curr + df >= h[idx])
			ret = min(ret, sum(curr + df) - sum(curr) + go(idx + 1, curr + df));
	}
	//cout<<idx<<" "<<curr<<" ret = "<<ret<<endl;
	return dp[ {idx, curr}] = ret;
}
// int bf(){
	
// }
void solve() {
	dp.clear();
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> k[i];
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	cout << min(go(1, 0), sum(k[n])) << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("out.txt","r",stdin);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}
/*

3 1 ret = 2
3 1 ret = 2
3 3 ret = 3
2 2 ret = 3
1 0 ret = 6
6

5 7 9
2 1 2

*/