#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector<string> fun[55];
void solve() {
	int n;cin>>n;

	for(int i=0;i<fun[n].size();i++){
		cout<<fun[n][i]<<endl;
	}
}
void gen(){
	fun[1].push_back("()");

	for(int i=2;i<=50;i++){
		string temp = "()" +fun[i-1][0];
		fun[i].push_back(temp);
		for(int j=0;j<fun[i-1].size();j++){
			temp = "(" +fun[i-1][j]+ ")";
			fun[i].push_back(temp);
		}
		//cout<<fun[i].back()<<endl;
	}
}
int  main ()
{
 	gen();
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	

	return 0;
}