#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
unordered_map<ll,bool> mp,mp2;
bool fun(ll x){
	if(mp[x])
		return mp2[x];
	mp[x]=1;
	ll xx = x;
	vector<int>r,res;
	while(x){
		res.push_back(x%10);
		x/=10;
	}
	r = res;
	reverse(res.begin(),res.end());
	if(res == r){
		//cout<<xx<<" palin\n";
		return mp2[xx]=true;
	}
	return mp2[xx] = false;
}
void solve() {
	//cout<<setprecision(10)<<fixed<<PI<<endl;
	ll A;cin>>A;
	ll sq = sqrtl(A);
	int res=0;
	for(ll i=1;i<=sq;i++){
		if(A%i==0){
			if(fun(i))
				res++;
			if(i*i != A){

				if(fun(A/i))
					res++;
			}
		}
	}
	cout<<res<<endl;
}
int  main ()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cout<<"Case #"<<tc<<": ";
		solve();
	}
	return 0;
}