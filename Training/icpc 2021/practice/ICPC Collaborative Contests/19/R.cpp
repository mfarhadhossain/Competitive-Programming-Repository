#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	string s;cin>>s;
	for(int i=1;i<s.size();i++){
		if(s[i]<s[i-1]){
			cout<<"-1\n";
			return;
		}
	}
	//cout<<go(1,)
}
int  main ()
{
	cout<<(-100)%9<<endl;
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	// int t = 1; cin >> t;
	// for (int tc = 1; tc <= t; tc++)
	// 	solve();
	return 0;
}