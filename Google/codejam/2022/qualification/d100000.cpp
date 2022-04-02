#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	vector<int>s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s.begin(),s.end());

	int x=1,res=0;

	for(int i=0;i<n;i++){
		if(s[i]>=x){
			x++;
			res++;
		}
	}
	cout<<res<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}