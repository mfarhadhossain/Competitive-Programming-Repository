// template credit mh755628's github
#include<bits/stdc++.h>
using namespace std;
struct SA {
	int n; vector <int> lcp, sa, rank;
	vector <vector <int> > t;
	SA() {}
	SA(string str) : n(str.size()) {
		vector <int> p(n), c(n), cnt(max(1 << 8, n), 0);
		for (int i = 0; i < n; i++) cnt[str[i]]++;
		for (int i = 1; i < (1 << 8); i++) cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; i++) p[--cnt[str[i]]] = i;
		int cc = 1; c[p[0]] = 0;
		for (int i = 1; i < n; i++) {cc += str[p[i]] != str[p[i - 1]]; c[p[i]] = cc - 1;}
		vector <int> pn(n), cn(n);
		for (int h = 0; (1 << h) < n; h++) {
			for (int i = 0; i < n; i++) pn[i] = (p[i] - (1 << h) + n) % n;
			fill(cnt.begin(), cnt.begin() + cc, 0);
			for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
			for (int i = 1; i < cc; i++) cnt[i] += cnt[i - 1];
			for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
			cc = 1; cn[p[0]] = 0;
			for (int i = 1; i < n; i++) {
				pair <int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]}, prv = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
				cc += (prv != cur);
				cn[p[i]] = cc - 1;
			}
			c.swap(cn);
		}
		sa = p; rank.resize(n); lcp.resize(n, 0);
		for (int i = 0; i < n; i++) rank[sa[i]] = i;
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (rank[i] == n - 1) {k = 0; continue;}
			int j = p[rank[i] + 1];
			while (i + k < n && j + k < n && str[i + k] == str[j + k]) ++k;
			lcp[rank[i]] = k;
			if (k) --k;
		}
	}
	void build_rmq() {
		int l = 32 - __builtin_clz(n);
		t = vector <vector <int> > (l, vector <int> (n, 0));
		for (int i = 0; i < n; i++) t[0][i] = lcp[i];
		for (int i = 1; i < l; i++) {
			for (int j = 0; j + (1 << i) - 1 < n; j++) {
				t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	int query(int l, int r) {
		int h = 31 - __builtin_clz(r - l + 1);
		return min(t[h][l], t[h][r - (1 << h) + 1]);
	}
	int find_left(int i, int k) {
		int l = 1, r = rank[i] - 1, j = rank[i];
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query(mid, rank[i] - 1) >= k) j = mid, r = mid - 1;
			else l = mid + 1;
		}
		return j;
	}
	int find_right(int i, int k) {
		int l = rank[i] + 1, r = n - 1, j = rank[i];
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query(rank[i], mid - 1) >= k) j = mid, l = mid + 1;
			else r = mid - 1;
		}
		return j;
	}
};
void solve() {
	string ss; cin >> ss;
	//sa obj(ss);
	ss.push_back('$');
	SA obj(ss);
	for (int i = 0; i < ss.size(); i++)
		cout << obj.sa[i] << ' ';
	puts("");
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}