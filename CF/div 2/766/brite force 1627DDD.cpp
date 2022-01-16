// for tle
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	vector<int>ar,cnt(MAX);

	for (int i = 1; i <= n; i++) {
		cin >> x;
		cnt[X]=1;
	}
	int res=0;
	while (true) {
		vector<int>temp;
		int good = false;

		for (int i = 0; i < ar.size(); i++) {
			for (int j = i + 1; j < ar.size(); j++) {
				int g = __gcd(ar[i], ar[j]);
				if (cnt[g] == 0) {
					res++;
					temp.push_back(g);
					cnt[g] = 1;
					good = true;
				}
			}
		}
		if (good == false)break;

		for(auto x:temp)
			ar.push_back(x);
	}
	cout<<res<<endl;
}

int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}