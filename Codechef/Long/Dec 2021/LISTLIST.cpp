#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,x;cin>>n;
	map<int,int>cnt;

	for(int i=0;i<n;i++){
		cin>>x;
		cnt[x]++;
	}
	if(cnt.size()==1){
		cout<<"0\n";
		return;
	}
	int res=1e9;
	for(int i=1;i<=n;i++){
		if(cnt[i]>=2){
			res=min(res,n-cnt[i]+1);
		}
	}
	if(res==1e9)res=-1;
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