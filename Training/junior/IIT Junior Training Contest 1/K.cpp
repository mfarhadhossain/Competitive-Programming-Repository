#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
pair<int, int> go(char ch, pair<int, int> pos) {
	int x = pos.first;
	int y = pos.second;
	if (ch == 'L')return {x - 1, y};
	if (ch == 'R')return {x + 1, y};
	if (ch == 'U')return {x , y + 1};
	return {x, y - 1};
}
void print(pair<int, int> pos) {
	cout << pos.first << " " << pos.second << endl;
}
void solve() {
	string s; cin >> s;
	pair<int, int>pos(0, 0), home(0, 0);
	for (int i = 0; i < s.size(); i++) {
		pair<int, int> curr(0, 0);
		pos = go(s[i], pos);

		for (int j = 0; j < s.size(); j++) {
			if (go(s[j], curr) == pos )continue;
			curr = go(s[j], curr);
		}
		if (curr == home) {
			print(pos);
			return;
		}
	}
	print(home);
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