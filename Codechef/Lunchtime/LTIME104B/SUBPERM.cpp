#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,k;cin>>n>>k;
	if(k == 1){
		if(n == 1){
			cout<<"1\n";
			return;
		}
		cout<<"-1\n";
		return;
	}

	for(int i=1;i<=k-1;i++){
		cout<<i<<" ";
	}
	for(int i=n;i>=k;i--){
		if(i==k){
			cout<<i;
		}
		else cout<<i<<" ";
	}
	cout<<endl;
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