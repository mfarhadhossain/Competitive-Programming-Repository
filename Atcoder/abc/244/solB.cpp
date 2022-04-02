#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	string s;cin>>s;
	int curr_x = 0 , curr_y = 0;
	int dir = 0;
	// 0 = east
	// 1 = south
	// 2 = west 
	// 3 = north
	for(int i=0;i<n;i++){
		if(s[i]=='S'){
			if(dir == 0)
				curr_x++;
			if(dir == 1)
				curr_y--;
			if(dir == 2)
				curr_x--;
			if(dir == 3)
				curr_y++;
		}
		else{
			dir = (dir+1)%4;
			//dir%=4;
		}
	}
	cout<<curr_x<<" "<<curr_y<<endl;
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