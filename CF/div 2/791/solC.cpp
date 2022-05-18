#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, q; cin >> n >> q;
	set<int>hor, ver;
	while (q--) {
		// cout << "horizontal rooks: ";
		// for (auto x : hor)
		// 	cout << x << " ";
		// cout << endl;
		// cout << "vertical rooks: ";
		// for (auto x : ver)
		// 	cout << x << " ";
		// cout << endl;
		int type; cin >> type;

		if (type == 1) {
			int r, c; cin >> r >> c;
			hor.insert(r);
			ver.insert(c);
		}
		else if (type == 2) {
			int r, c; cin >> r >> c;

			hor.erase(hor.lower_bound(r));
			ver.erase(ver.lower_bound(c));
		}
		else {
			bool yes = 0;
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			auto it1 = hor.lower_bound(x1);
			auto it2 = hor.lower_bound(x2);
			if( *it1 == x1 && *it2 == x2){
				if( distance(it1,it2) == x2-x1){
					yes = 1;
				}
			}
			it1 = ver.lower_bound(y1);
			it2 = ver.lower_bound(y2);
			if( *it1 == y1 && *it2 == y2){
				if( distance(it1,it2) == y2-y1){
					yes = 1;
				}
			}
			if (yes) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
	}

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