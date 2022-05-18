#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	vector<int> A(n), B(n), C(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	map<int, int> taken;
	ll res = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> C[i];

		if (C[i]) {
			taken[C[i]] = 1;
		}
		else {
			if (taken[A[i]]) {
				taken[A[i]]=1;
				continue;
			}
			if (taken[B[i]]) {
				taken[B[i]]=1;
				continue;
			}
			cout<<A[i]<<","<<B[i]<<endl;
			res = res * 2;
			res %= MOD;
			taken[A[i]]=1;
			taken[B[i]]=1;
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