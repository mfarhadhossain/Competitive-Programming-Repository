#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	deque<int>dq;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		dq.push_back(x);
	}
	int res = 0, last = -1e9;

	while (!dq.empty()) {
		if (dq.front() >= last && dq.back() >= last) {
			if (dq.front() < dq.back()) {
				res++;
				last = max(last,dq.front());
				dq.pop_front();
			}
			else {
				res++;
				last = max(last,dq.back());
				dq.pop_back();
			}
		}
		else if (dq.front() >= last) {
			res++;
			last = max(last,dq.front());
			dq.pop_front();
		}
		else if (dq.back() >= last) {
			res++;
			last = max(last,dq.back());
			dq.pop_back();
		}
		else{
			last = max(last,dq.back());
			dq.pop_back();
		}
	}
	cout << res << endl;

}
int  main ()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}