#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n;cin >> n;

	if(n<42){
		cout<<"AGC";
		if(n<10)cout<<"00"<<n<<endl;
		else if(n<100)cout<<"0"<<n<<endl;
	}
	else{

		cout<<"AGC";
		cout<<"0"<<n+1<<endl;
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