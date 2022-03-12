#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {

	ll x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2>> y2;
	vector< pair<ll,ll> > lp,lp2;
	for(int i=-10;i<=10;i++){
		for(int j=-10;j<=10;j++){
			ll x3 = x1+i;
			ll y3 = y1+j;
			if( (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3) == 5){
				lp.push_back({x1+i,y1+j});
			}
		}
	}
	for(int i=-10;i<=10;i++){
		for(int j=-10;j<=10;j++){

			ll x3 = x2+i;
			ll y3 = y2+j;

			if( (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) == 5){
				lp2.push_back({x2+i,y2+j});
			}
		}
	}

	for(auto x:lp){
		for(auto y:lp2){

			if(x==y){
				cout<<"Yes\n";
				return;
			}
		}
	}
		cout<<"No\n";
}
int  main ()
{
	map<int,vector<int>>mp;

	vector<int>tmp;

	
	mp[2] = tmp;

	cout<<mp[2].size()<<endl;

	return 0;
}