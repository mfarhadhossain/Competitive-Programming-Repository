#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1005, MOD = 1e9 + 7;
int dp[MAX][MAX], dp2[MAX][MAX];
bool ispalindrome(int l, int r, string &s) {
	if (l >= r)
		return dp[l][r] = 1;
	if (dp[l][r] != -1)
		return dp[l][r];

	if (s[l] == s[r])
		return dp[l][r] = ispalindrome(l + 1, r - 1, s);
	return dp[l][r] = 0;
}
void longestPalindrome(string s) {
	int n = s.size();
	int b = 0, e = 0, maximum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			ispalindrome(i, j, s);
		}
	}
}
int go(int b, int e) {
	if (b >= e) {
		return dp2[b][e] = 0;
	}
	if (dp[b][e] == true) {
		return dp2[b][e] = 0;
	}
	if (dp2[b][e] != -1)
		return dp2[b][e];
	int ret = e - b;
	for (int i = b; i <= e; i++) {
		if (dp[b][i] == true) {
			ret = min(ret, 1 + go(i + 1, e));
		}
	}
	return dp2[b][e] = ret;
}
int minCut(string &s) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			dp[i][j] = -1;
			dp2[i][j] = -1;
		}
	}
	longestPalindrome(s);
	return go(0, s.size() - 1) + 1;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		string s; cin >> s;
		cout << "Case " << tc << ": " << minCut(s) << endl;
	}
	return 0;
}