#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	ll n, a, b, c, res = 0;
	cin >> n >> a >> b >> c;
	n = n * 2;
	for (int i = 0; i <= c; i++) {
		for (int j = 0; j <= b; j++) {
			ll rem = n - (4 * i + 2 * j);
			if (rem < 0)break;
			if (rem <= a)res++;
		}
	}
	cout << res << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin>>t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}