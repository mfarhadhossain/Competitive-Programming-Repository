#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 150007, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	vector<int>pos[MAX];
	for(int i=0;i<n;i++){
		int x;cin>>x;
		pos[x].push_back(i+1);
	}


	int gd = false;
	int res=0;
	for(int i=1;i<MAX;i++){
		if(pos[i].size()<=1)continue;

		gd = true;

		for(int j=1;j<pos[i].size();j++){

			int left1 = max(0,pos[i][j-1]-1);
			int right1 = max(n-pos[i][j-1],0);
			int left2 = max(0,pos[i][j]-1);
			int right2 = max(n-pos[i][j],0);

			res=max(res,1 + min(left1,left2)+ min(right1,right2));
		}
	}
	if(gd == false){
		cout<<"-1\n";
		return;
	}
	cout<<res<<endl;
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