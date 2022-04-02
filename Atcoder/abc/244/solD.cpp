#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	string s1,s2,s3,t1,t2,t3;
	cin>>s1>>s2>>s3;
	cin>>t1>>t2>>t3;
	//cout<<"Yes\n";
	if(s1==t1 and s2!=t2 and s3!=t3){
		cout<<"No\n";
	}
	else if(s1!=t1 and s2==t2 and s3!=t3){
		cout<<"No\n";
	}
	else if(s1!=t1 and s2!=t2 and s3==t3){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
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