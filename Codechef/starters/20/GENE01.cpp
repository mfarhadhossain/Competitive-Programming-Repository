#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	string ch1,ch2;
	cin>>ch1>>ch2;
	if(ch1==ch2){
		cout<<ch1<<endl;
		return;
	}
	if(ch1=="R" or ch2=="R"){
		cout<<"R\n";
	}
	else if(ch1=="B" or ch2=="B"){
		cout<<"B\n";
	}
	else{
		cout<<"G\n";
	}
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