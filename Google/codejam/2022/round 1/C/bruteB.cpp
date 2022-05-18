#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout<<x<<endl
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool badword(string x) {
	vector<int> pos[26];
	int i = 0;
	for (auto y : x)
		pos[y - 'A'].push_back(i++);
	int bad = 0;
	for (int i = 0; i < 26; i++) {
		if (pos[i].size() == 1)
			continue;


		for (int j = 1; j < pos[i].size(); j++) {
			if (pos[i][j - 1] + 1 != pos[i][j])bad |= 1;
		}
	}
	//cout<<x<<" "<<bad<<endl;
	return bad;
}
void solve() {
	int n, k; cin >> n >> k;
	vector<ll> v(n);
	ll  sum = 0, nonzero = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		if (v[i])nonzero++;
	}
	if (sum == 0) {
		if (nonzero == 0)
			cout << "0\n";
		else cout << "IMPOSSIBLE\n";
		return;

	}
	sum = sum;
	// 2ab+2ac+2ad+...
	ll sum1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			sum1 += v[j] * v[i];
		}
	}
	//cout<<sum<<" "<<sum1<<endl;
	if (sum1 % sum) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << (-sum1 / sum) << "\n";
}
int  main ()
{

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}