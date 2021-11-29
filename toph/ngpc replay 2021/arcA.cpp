#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MAX = 1e5 + 10;
ll fun(ll x){
	return x*(x-1)/2;
}
void solve() {
	string s1,s2;cin>>s1>>s2;

	sort(s1.begin(),s1.end());
	sort(s2.rbegin(),s2.rend());


	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());

	
	cout<<s1<<endl;
	cout<<s2<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t = 1;// cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}