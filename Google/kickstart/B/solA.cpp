#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
#define PI acos(-1.0)
void solve() {
	//cout<<setprecision(10)<<fixed<<PI<<endl;
	double R,A,B;

	cin>>R>>A>>B;
	double res=0.0,curr = R;
	int step = 1;
	while((int)curr){
		res+= PI*curr*curr;
		if(step&1)
			curr = curr*A;
		else curr = floor(curr/B);
		step++;
	}
	cout<<setprecision(10)<<fixed<<res<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cout<<"Case #"<<tc<<": ";
		solve();
	}
	return 0;
}