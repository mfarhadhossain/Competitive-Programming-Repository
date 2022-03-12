#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector<int>dv;
int distance(int x,int y){
	int res=0;
	while(x && y){
		int r1 = x%10;
		int r2 = y%10;
		if(r1!=r2){
			res++;
		}
		x/=10;
		y/=10;
	}
	if(x or y)return 1e9;
	return res;
}
void solve() {
	int n;cin>>n;
	int mn = 1000,res=n;
	for(int i=0;i<dv.size();i++){
		int d = distance(dv[i],n);
		if(d < mn){
			mn = d;
			res = dv[i];
		}
	}	
	cout<<res<<endl;
}
int  main ()
{

	for(int i=14;i<=2000;i+=7){
		if(i%7==0){
			dv.push_back(i);
		}	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}