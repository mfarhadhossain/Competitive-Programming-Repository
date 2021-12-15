#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int numberofone(ll x){
	int res=0;
	while(x){
		if(x&1)res++;
		x/=2;
	}
	return res;
}
void solve() {
	ll n,xo=0;cin>>n;
	// set<ll>s;
	// for(int i=1;i<=n;i++){
	// 	for(int j=i;j<=n;j++){
	// 		xo = i^j;
	// 		s.insert(xo);
	// 	}
	// }
	// cout<<s.size()<<" ";
	if(n==2){
		cout<<"2\n";
		return;
	}
	if( numberofone(n) == 1){

		n = ((n%MOD) * 2)%MOD;
		n = (n + (-1)%MOD)%MOD;
		n+=MOD;
		n%=MOD;
		cout<<n<<"\n";
	}
	else{
		int cnt=0;
		while(n){
			cnt++;
			n/=2;
		}
		ll res = 1;
		while(cnt){
			res=((res%MOD)*2LL)%MOD;
			cnt--;
		}
		cout<<res<<endl;
	}
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