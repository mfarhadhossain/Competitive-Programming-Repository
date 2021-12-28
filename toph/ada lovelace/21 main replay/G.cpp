#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool possible(ll t,vector<int>&v,ll x,ll y){
	vector<ll>tmp;
	for(int i=0;i<v.size();i++){
		tmp.push_back(x*t);
	}
	tmp.push_back(y*t);
	sort(tmp.begin(),tmp.end());
	int bad=0;
	for(int i=0;i<v.size();i++){
		if(v[i]>tmp[i+1]){
			bad++;
		}
	}
	return bad<=t;
}
void solve() {
	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ll x,y;cin>>x>>y;

	ll lo=1,hi=1e9+7,res=1e9;
	while(lo<hi){
		ll md = (lo+hi)/2;

		if(possible(md,v,x,y)){
			hi=md-1;
			res=min(res,md);
		}
		else{
			lo=md+1;
		}
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