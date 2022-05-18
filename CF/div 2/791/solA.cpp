#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	ll n;cin>>n;
	if(n&1 or n<4){
		cout<<"-1\n";
		return;
	}
	if(n==4 or n==6){
		cout<<"1 1\n";
		return;
	}
	ll mn = n/6;
	if(n%6==4 or n%6==2){
		mn++;
	}
	ll mx = n/4;
	cout<<mn<<" "<<mx<<endl;
	
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