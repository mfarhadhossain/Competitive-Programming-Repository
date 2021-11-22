#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n, a, b; cin >> n >> a >> b;
	int mid = n / 2;

	vector<int>L, taken(n + 1);
	L.push_back(a);
	taken[a]=1;
	for (int i = b + 1; i <= n; i++) {
		if(taken[i])continue;

		L.push_back(i);
		taken[i] = 1;
	}
	if (L.size() > mid) {
		cout << "-1\n";
		return;
	}
	vector<int>R;
	R.push_back(b);
	taken[b]=1;
	for (int i = 1; i < a; i++) {
		if(taken[i])continue;

		R.push_back(i);
		taken[i] = 1;
	}
	if (R.size() > mid) {
		cout << "-1\n";
		return;
	}
	int i = 1;
	while (R.size() < mid && i < b) {
		if (taken[i] == 0 && i!=a) {
			taken[i] = 1;
			R.push_back(i);
		}
		i++;
	}
	i=a+1;
	while (L.size() < mid && i <= n) {
		if (taken[i] == 0 && i!=b) {

			taken[i] = 1;
			L.push_back(i);
		}
		i++;
	}
	if (L.size() != mid or R.size() != mid) {
		cout << "-1\n";
		return;
	}
	for (auto x : L)cout << x << " ";
	for (auto x : R)cout << x << " ";
	cout << endl;
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}