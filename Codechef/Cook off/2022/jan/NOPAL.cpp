#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;

	for(int i=0,j=0;i<n;i++,j++){
		j=j%26;
		char ch = (char)(j+'a');
		cout<<ch;
	}
	cout<<"\n";
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
/*
1 3 5 7
1-7 = 8/2 = 4
3-5 = 8/2 = 4
res = 8


*/