#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e6 + 7, MOD = 1e9 + 7;
map<string, int> m;
int par[MAX], sz[MAX];
void init(int n) {
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int find_par(int x) {
	if (x == par[x])
		return x;
	return x = find_par(par[x]);
}
void Union(int u, int v) {
	int par_u = find_par(u);
	int par_v = find_par(v);
	if (sz[par_u] > sz[par_v]) {
		sz[par_u] += sz[par_v];
		par[par_v] = par_u;
	}
	else {
		sz[par_v] += sz[par_u];
		par[par_u] = par_v;
	}
}
void solve() {
	int n; cin >> n;
	init(n);
	string s[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		m[s[i]] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		if (x == s[i])continue;
		Union(m[s[i]], m[x]);
	}
	vector<int>res;
	for (int i = 1; i <= n; i++) {
		if (find_par(i) == i) {
			res.push_back(sz[i]);
		}
	}
	for (int i = 0; i < res.size(); i++) {
		if (i)cout << " ";
		if (res[i] > 1)res[i] /= 2;
		cout << res[i];
	}
	cout << endl;
}
void solve2() {
	int n; cin >> n;
	//init(n);
	string s[n + 7], t[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	set<string> carry;
	vector<int>res;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {
			if (carry.size()) {
				res.push_back(carry.size());
				carry.clear();
			}
			res.push_back(1);
		}
		else {
			carry.insert(s[i]);
			carry.insert(t[i]);
		}
	}

	if (carry.size()) {
		res.push_back(carry.size());
		carry.clear();
	}
	for (int i = 0; i < res.size(); i++) {
		if (i)cout << " ";
		//if (res[i] > 1)res[i] /= 2;
		cout << res[i];
	}
	cout << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve2();
	return 0;
}
/*
3
5
A
B
C
D
E
A
C
D
B
E
3
RED
BLUE
ORANGE
RED
BLUE
ORANGE
3
MOE
LARRY
CURLY
CURLY
MOE
LARRY

*/