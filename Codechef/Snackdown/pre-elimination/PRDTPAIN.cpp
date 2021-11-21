#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
ll fun(ll x,ll y,ll z){
	return (x-y)*(y-z);
}
ll gun(int i,vector<int>&v){
	return max({fun(v[i],v[i+1],v[i+2]),
		fun(v[i],v[i+2],v[i+1]),
		fun(v[i+1],v[i],v[i+2]),
		fun(v[i+1],v[i+2],v[i]),
		fun(v[i+2],v[i],v[i+1]),
		fun(v[i+2],v[i+1],v[i])
	});
}
void solve() {
	int n;cin>>n;
	vector<int>v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	vector<ll>mul;
	ll res=0;
	for(int i=0;i+2<n;i++){
		mul.push_back(gun(i,v));
		cout<<i<<" "<<i+1<<" "<<i+2<<" max= "<<mul.back()<<endl;
		res+=mul.back();
	}
	for(int i=4;i<=n;i++){
		vector<ll>tmp;
		for(int i=0;i+1<mul.size();i++){
			tmp.push_back( max(mul[i],mul[i+1]));
			res+=tmp.back();
		}
		mul=tmp;
	}
	cout<<res<<endl;
}
int  main ()
{
	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}