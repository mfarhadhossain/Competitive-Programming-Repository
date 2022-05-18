#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	vector<int>res[20];
	int n;cin>>n;
	vector<int>last={1};

	for(int i=2;i<=n;i++){
		vector<int>tmp;
		tmp = last;
		tmp.push_back(i);
		for(auto x:last)
			tmp.push_back(x);
		last= tmp;
	}
	for(auto x:last){
		cout<<x<<" ";
	}
	cout<<endl;
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