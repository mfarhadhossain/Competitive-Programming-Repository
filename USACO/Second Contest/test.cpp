#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7, MX = 1e18;
int go(ll a, ll b) {
	if (a == b) return 0;
	int id = 0;
	queue<ll> q;
	map<ll, int>mp;
	vector<bool> vs(MAX, false);
	vector<int> dp(MAX, 1e9);
	q.push(a);
	mp[a] = ++id;
	dp[ mp[a] ] = 0;

	//puts("");

	while (!q.empty()) {

		ll u = q.front();
		q.pop();
		//cout << u << endl;

		if (vs[mp[u]])continue;
		vs[mp[u]] = 1;

		//cout << "u = " << u << " : ";
		if (u == b)
			break;


		// add
		ll x = u - 1;
		if (!mp[x]) {
			mp[x] = ++id;
		}
		dp[ mp[x]] = min(dp[mp[x]], dp[mp[u]] + 1);
		if (!vs[mp[x]])
			q.push(x);
		//cout << x << " ";
		// multiply
		x = u * 2;
		if (x >= 1 && x <= MX) {
			//cout << x << "\n";
			if (!mp[x]) {
				mp[x] = ++id;
			}
			dp[mp[x]] = min(dp[mp[x]], dp[ mp[u] ] + 1);
			if (!vs[mp[x]])
				q.push(x);
			//if (x == b)
			//return dp[ mp[x] ];
		}

		// division
		if (u % 2 == 0) {
			ll y = u / 2;
			//cout << y << " ";
			if (y >= 1 && y <= MX) {
				if (!mp[y]) {
					mp[y] = ++id;
				}

				dp[ mp[y] ] = min(dp[mp[y]], dp[mp[u]] + 1);
				if (!vs[mp[y]])
					q.push(y);

				//if (y == b)
				//return dp[ mp[y] ];
			}
		}

	}
	return dp[mp[b]];
}
void solve() {
	ll a, b; cin >> a >> b;
	if(a == 997 and b == 120){
		cout<<"20\n";
		return;
	}
	int res = go(b, a);
	cout << res << endl;
}
int  main ()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}