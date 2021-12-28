#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	string a,b;cin>>a>>b;
	int u=0,u2=0;

	for(int i=0;i<n;i++){
		if(a[i]=='1' && b[i]=='0')u++;
		if(a[i]!=b[i])u2++;
	}
	cout<<min(u,u2)<<endl;
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