#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	string s;cin>>s;
	// oxx
	string a = "oxx";
	string b = "xxo";
	string c = "xox";
	// xxo
	// xox
	int cnt=0;
	for(int i=0,j=0;i<s.size();i++){
		if(s[i]==a[j%3]){
			j++; cnt++;
		}
	}
	if(cnt==s.size()){
		cout<<"Yes\n";
		return;
	}
	cnt=0;
	for(int i=0,j=0;i<s.size();i++){
		if(s[i]==b[j%3]){
			j++; cnt++;
		}
	}
	if(cnt==s.size()){
		cout<<"Yes\n";
		return;
	}
	cnt=0;
	for(int i=0,j=0;i<s.size();i++){
		if(s[i]==c[j%3]){
			j++; cnt++;
		}
	}
	if(cnt==s.size()){
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

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}