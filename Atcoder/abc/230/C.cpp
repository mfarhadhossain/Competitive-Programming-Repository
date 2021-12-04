#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	ll N,A,B,p,q,r,s;cin>>N>>A>>B;
	cin>>p>>q>>r>>s;
	ll st = max(1LL-A, 1LL-B);
	ll en = min(N-A, N-B);


	ll st2 = max(1LL-A, B-N);
	ll en2 = min(N-A, B-1);


	for(ll i=p;i<=q;i++){
		for(ll j=r;j<=s;j++){
			if(i-A==j-B&& i-A>=st&&i-A<=en){
				cout<<"#";
			}
			else if(i-A==B-j&& i-A>=st2&&i-A<=en2){
				cout<<"#";
			}
			else{
				cout<<".";
			}
		}
		cout<<endl;
	}
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