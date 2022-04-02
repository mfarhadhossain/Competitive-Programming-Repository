#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int a,b,c,d;cin>>a>>b>>c>>d;
	if( a*60 + b < c*60+d+1){
		cout<<"Takahashi\n";
	}
	else{
		cout<<"Aoki\n";
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