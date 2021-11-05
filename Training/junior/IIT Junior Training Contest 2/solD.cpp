#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	std::multiset< pair<int, int> > mul;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (n == 1) {
			if (x == 1) {
				cout << "1 1\n";
				return;
			}
			else {
				cout << "0\n";
				return;
			}
		}
		mul.insert(make_pair(i, x));
	}
	std::vector<int> res;
	pair<int, int> curr , pr;

	pr = { -1, -1};
	while (!mul.empty()) {

		int good = 0;
		multiset< pair<int, int> > mul2;
		for (auto x : mul) {
			curr = x;
			//cout << "current element " << x.second << "\n";
			//cout << "pr element " << pr.second << "\n";
			if (pr.first == -1 && pr.second == -1) {
				mul2.insert(x);
				pr = x;
				continue;
			}
			else {
				int curr_genre = curr.second;
				int prev_genre = pr.second;

				if (__gcd(curr_genre, prev_genre) == 1) {
					//mul.erase(mul.lower_bound(curr));
					good = 1;
					res.push_back(curr.first + 1);
					pr = { -1, -1};
				}
				else {
					pr = curr;
					mul2.insert(curr);
				}
			}
		}
		if (good == 0) {
			break;
		}
		mul = mul2;
	}

	cout << res.size();
	for (int x : res)
		cout << " " << x;
	cout << endl;

}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	while (t--)solve();
	return 0;
}