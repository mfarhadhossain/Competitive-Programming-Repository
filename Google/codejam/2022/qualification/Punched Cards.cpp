#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int r,c;cin>>r>>c;
	for(int i=1;i<=2*r + 1;i++){
		for(int j=1;j<=2*c+1;j++){
			if(i<=2 && j<=2)cout<<".";
			else if(j&1){
				if(i&1){
					cout<<"+";
				}
				else{
					cout<<"|";
				}
			}
			else{
				if(i&1)
				cout<<"-";
				else
				cout<<".";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cout<<"Case #"<<tc<<":\n";
		solve();
	}
	return 0;
}