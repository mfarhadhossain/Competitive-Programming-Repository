#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
string tostring(int x){
	string res= "";
	while(x){
		int r = x%10;
		x/=10;
		char ch = r+'0';
		res.push_back(ch);
	}
	reverse(res.begin(),res.end());
	return res;
}
void solve() {
	string s;cin>>s;

	int n = s.size();
	int pos = -1,sum=0;
	for(int i = n-1;i>0;i--){
		int d = (s[i]-'0')+(s[i-1]-'0');
		if(d>=10){
			pos = i;
			sum = d;
			break;
		}
	}
	if(pos!=-1){

		string res="";
		for(int i=0;i<pos-1;i++){
			res.push_back(s[i]);
		}
		res+=tostring(sum);

		for(int i=pos+1;i<n;i++){

			res.push_back(s[i]);
		}
		cout<<res<<endl;
		return;
	}

		string res="";
		sum=0;
		for(int i=0;i<2;i++){
			int d = s[i]-'0';
			sum+=d;
		}
		res+=tostring(sum);

		for(int i=2;i<n;i++){

			res.push_back(s[i]);
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