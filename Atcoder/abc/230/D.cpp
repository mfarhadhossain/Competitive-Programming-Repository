#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	ll n,d;cin>>n>>d;

	vector<ll>l(n),r(n);
	vector<pair<ll,ll>>v;
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
		v.push_back({r[i],l[i]});
	}
	sort(v.begin(),v.end());
	ll x = d-1;
	int res=0;
	ll curr=0;
	for(int i=0;i<n;i++){
		if(curr>=v[i].second)continue;
		curr=v[i].first+x;
		res++;
	}
	cout<<res<<endl;
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