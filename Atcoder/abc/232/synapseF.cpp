#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,x,y;cin>>n>>x>>y;
	vector<ll>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	ll s=0;
	for(int i=0;i<x;i++){
		s+=v[i];
	}
	ll res=max(0LL,s-y);
	ll ret=res;
	for(int i=x-1;i>=0;i--){
		int q=min(ret,v[i]);
		v[i]-=q;
		ret-=q;
		s-=q;
	}
	for(int i=0;i<n;i++)
		cout<<v[i]<<' ';
	cout<<endl;
	
	for(int i=x,j=0;i<n;i++,j++){
		if(s+v[i] > y){

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