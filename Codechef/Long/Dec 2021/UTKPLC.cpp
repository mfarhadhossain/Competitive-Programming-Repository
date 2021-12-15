#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	map<string,int> ar;
	string s,res;
	int mx=10;
	for(int i=0;i<3;i++){
		cin>>s;
		ar[s]=i;
	}
	
	for(int i=0;i<2;i++){
		cin>>s;
		if(ar[s]<mx){
			mx = ar[s];
			res=s;
		}
	}
	cout<<res<<endl;
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