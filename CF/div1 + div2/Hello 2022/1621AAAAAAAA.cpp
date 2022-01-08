#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,k;cin>>n>>k;
	int mx= n/2 + (n%2);

	if(k>mx){
		cout<<"-1\n";
		return;
	}
	bool rook[n+7][n+7];
	memset(rook,false,sizeof rook);
	int x = 0 , y = 0;
	while(x<n){
		rook[x][y]=1;
		x+=2;
		y+=2;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(rook[i][j]&&k){
				cout<<'R';
				k--;
			}
			else cout<<".";
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
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}