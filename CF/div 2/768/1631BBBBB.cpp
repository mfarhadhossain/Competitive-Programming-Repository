#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5 + 10, MOD = 1e9 + 7;
int ar[MAX];
void solve() {

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int res = 0, curr = 1, i = n - 2, jump = 0;

	while (i >= 0) {
		if (ar[i] == ar[n - 1]) {
			curr++;
			i--;
		}
		else {
			jump = curr;
			i = i - jump;
			curr = curr + jump;
			res++;
		}
	}
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