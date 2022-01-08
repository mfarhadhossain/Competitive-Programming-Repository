#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool good(vector<int>&ar, int l, int r) {
	if (r - l + 1 == 2) {
		return true;
	}
	if (l == r) {
		return true;
	}

	int s = 0, len = r - l + 1;
	for (int i = l; i <= r; i++){

		s += ar[i];
		//cout<<ar[i]<<' ';
	}
	s = s * 2;
	int s2 = (ar[l] + ar[r]);
	if (s2 * len == s) {
		return (good(ar, l + 1, r)) and (good(ar, l, r - 1));
	}
	return false;
}
void print(vector<int>&ar) {
	cout<<"for: ";
	for (auto x : ar) {
		cout << x << " ";
	}
	//cout << endl;

}
void gen(int idx,int n, vector<int>ar) {
	if (idx > n) {
		print(ar);
		if (good(ar, 1, n)) {
			cout<<" good\n";
		}
		else{
			cout<<" ....\n";
		}
		//print(ar);
		return;
	}
	for (int i = 0; i <= 5; i++) {
		ar.push_back(i);
		gen(idx + 1, n,ar);
		ar.pop_back();
	}
}
void solve() {

	int n; cin >> n;

	vector<int>ar;
	ar.push_back(0);
	gen(1, n, ar);
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}