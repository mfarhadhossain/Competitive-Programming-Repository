#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	string s;cin>>s;
	int n = s.size();
	if(n&1){
		cout<<"No\n";
		return;
	}
	string a = s.substr(0,n/2);
	string b = s.substr(n/2);
	if(a==b){
		cout<<"Yes\n";
	}
	else{
		
		cout<<"No\n";
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