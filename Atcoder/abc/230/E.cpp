#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	ll n;cin>>n;
	ll sq=sqrtl(n),s=0;
	for(ll i=1;i<=sq;i++)
		s+=n/i;
	cout<<2*s-sq*sq<<endl;
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