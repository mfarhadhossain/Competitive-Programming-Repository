#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	unordered_map<int,int>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]=1;
	}
	int res1=0,res2=0;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(m[b[i]] && b[i]!=a[i])res2++;
	}
	for(int i=0;i<n;i++){
		if(a[i]==b[i])res1++;
	}
	cout<<res1<<"\n"<<res2<<endl;
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