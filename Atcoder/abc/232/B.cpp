#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;//cin>>n;
	string s,t;cin>>s>>t;
	n=s.size();
	map<int,int>m;
	for(int i=0;i<n;i++){
		int d = s[i]-t[i];
		m[d]=1;
	}
	if(m.size()==1){
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

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}