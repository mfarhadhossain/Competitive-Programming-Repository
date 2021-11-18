#include<bits/stdc++.h>
using namespace std;
#define end "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
int dp[1001][1001];
int go(int l, int r, string &s) {
	if (l > r)return 0;
	if (l == r)return dp[l][r] = 1;
	if (dp[l][r] != -1)
		return dp[l][r];
	int ret = 0;
	if (s[l] == s[r]) {
		ret = 2 + go(l + 1, r - 1, s);
	}
	else {
		ret = max(ret, go(l + 1, r, s));
		ret = max(ret, go(l, r - 1, s));
	}
	return dp[l][r] = ret;
}
void solve() {
	string s;
	getline(cin,s);
	if(s.size()<=1){
		cout<<s.size()<<"\n";
		return;
	}
	memset(dp, -1, sizeof dp);
	cout << go(0, (int)s.size() - 1, s) << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 1; cin >> t;
	getchar();
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}