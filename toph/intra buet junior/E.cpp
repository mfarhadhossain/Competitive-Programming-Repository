#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	ll n,h;cin>>n>>h;
	vector< pair<ll,ll> > v(n);
	for(int i=0;i<n;i++){ // ai
		cin>>v[i].first;
	}
	for(int i=0;i<n;i++){ // bi
		cin>>v[i].second;
	}
	sort(v.begin(),v.end());
	int res=0;
	for(int i=0;i<n;i++){

		if(h>=v[i].first){
			h-=v[i].first;
			h+=v[i].second;
			res++;
		}
		else{
			break;
		}
	}
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