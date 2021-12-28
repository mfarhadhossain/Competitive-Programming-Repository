#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool possible(int l1,int l2,int l3){
	if(l1+l2 == l3){
		return true;
	}
	if(l1==l2 and l3%2==0)
		return true;
	return false;
}
void solve() {
	int l1,l2,l3;
	cin>>l1>>l2>>l3;
	if(possible(l1,l2,l3) or possible(l1,l3,l2) or possible(l3,l2,l1)){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
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