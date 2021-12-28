#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,s=0; cin >> n;
	vector<int>ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		s+=ar[i];
	}
	if(s%n==0)cout<<"0\n";
	else cout<<"1\n";
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