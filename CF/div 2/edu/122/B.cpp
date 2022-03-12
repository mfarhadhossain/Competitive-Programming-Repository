#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	string s;cin>>s;

	int n = s.size();
	int zero=0,one=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0')zero++;
	}
	one = n - zero;

	if(one == 0 or zero == 0){
		cout<<"0\n";
		return;
	}
	if(one!=zero){
		cout<<min(one,zero)<<endl;
		return;
	}
	else{
		cout<<min(one,zero)-1<<endl;
		return;
	}
	// 00111100
	// 10001011
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