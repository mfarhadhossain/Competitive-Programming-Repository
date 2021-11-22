#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const int MAX = 1e5 + 10;
ll sum(ll x){
	return x*(x+1)/2;
}
ll cost(ll i,ll k){
	if(i<=k){
		return sum(i);
	}
	else{
		ll rem = i-k;
		ll x = k-1;
		x-=rem;
		return sum(k)+sum(x);
	}
}
void solve() {
	ll k,x;
	cin >> k >> x;

	ll lo=1,hi=2*k-1;
	while(hi-lo>5){

		ll mid = (lo+hi)/2;

		if(cost(mid,k)>x){
			hi=mid-1;
		}
		else{
			lo=mid;
		}
	}
	int g=0,res=0;
	lo-=10;
	if(lo<1)lo=1;
	hi+=10;
	if(hi>2*k-1)hi=2*k-1;
	for(int i=lo;i<=hi;i++){
		ll cst = cost(i,k);
		if(cst>=x){
		    res=max(res,i);
			break;
		}
		if(cst<x){
		    res=max(res,i);
		}
	}
	cout<<res<<endl;
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}