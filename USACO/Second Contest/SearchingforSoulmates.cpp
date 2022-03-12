#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int go(ll a,ll b){
	if(a==0)return 0;
	return 1 + go(a%b,b);
}
void solve() {
	ll a,b;cin>>a>>b;
	int res=go(a,b);
	cout<<res<<endl;
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