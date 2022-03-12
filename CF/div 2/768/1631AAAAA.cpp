#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, x; cin >> n;
	vector<int>ar(n), br(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> br[i];
	}
	int mx1 = *max_element(ar.begin(), ar.end());

	int mx2 = *max_element(br.begin(), br.end());
	int res = 0;

	for (int i = 0; i < n; i++) {
		if (ar[i] == mx1)continue;

		if (ar[i] < br[i] && mx1 >= mx2)
			swap(ar[i], br[i]);
	}
	for (int i = 0; i < n; i++) {
		if (br[i] == mx2)continue;

		if (br[i] < ar[i] && mx2 >= mx1)
			swap(ar[i], br[i]);
	}
	res = *max_element(ar.begin(), ar.end());
	res = res * (*max_element(br.begin(), br.end()));
	cout << res << endl;
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