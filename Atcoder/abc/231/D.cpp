#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, m; cin >> n >> m;
	vector<int>deg(n + 5);
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		deg[l]++;
		deg[r]++;
	}
	int cnt2 = 0, cnt1 = 0,cnt3=0;
	for (int i = 1; i <= n; i++) {
		if(deg[i]==0)continue;
		if (deg[i] == 2) {
			cnt2++;
		}
		else cnt3++;
	}
	if(cnt3){
		cout<<"No\n";
		return;
	}
	if (cnt2 <= n - 2)
		 cout << "Yes\n";
	else cout << "No\n";
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