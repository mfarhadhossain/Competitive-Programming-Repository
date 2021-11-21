#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
int fun(vector<int>&a) {
	int n = a.size();
	int res = a[0];
	for (int x : a)
		res = res & x;
	return res;
}
int evaluate(vector<int>v) {
	int n = v.size();
	int mask = 1 << n;
	map<int, int>map;
	for (int i = 1; i < mask; i++) {
		vector<int>v2;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				//cout<<j<<" ";
				v2.push_back(v[j]);
			}
		}
		int f = fun(v2);
		map[f] = 1;
		//cout<<" and = "<<f<<endl;
	}
	return map.size();

}
void solve() {
	int n; cin >> n;
	int mx = 1 << n;
	mx--;

	vector<int>res;
	res.push_back(mx);
	for (ll i = 1, j = 1; i <= n; i++) {

		res.push_back(mx - j);
		j *= 2;
	}
	while (res.size() < 2 * n) {
		res.push_back(0);
	}
	for (int i = 0; i < 2 * n; i++) {
		if (i)cout << " ";
		cout << res[i];
	}
	cout << endl;
	cout << evaluate(res) << endl;
}
int  main ()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; //cin>>t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}
