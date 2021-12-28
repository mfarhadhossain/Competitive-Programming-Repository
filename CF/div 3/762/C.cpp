#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector<int>ar;
ll fun(string ss){
	ll res;
	stringstream aw(ss);
	aw>>res;
	return res;
}
void solve() {
	string b="",a,s;cin>>a>>s;
	ll num1 = fun(a);
	vector<int>AQ,SQ;

	while(!a.empty() && !s.empty()){
		int a_d = a.back()-'0';
		int s_d = s.back()-'0';
		if(a_d <= s_d){
			AQ.push_back(a_d);
			SQ.push_back(s_d);
			a.pop_back();
			s.pop_back();
		}
		else{ // a_d > s_d
			s.pop_back();
			if(s.empty()){
				cout<<"-1\n";
				return;
			}
			s_d+=(s.back()-'0')*10;
			if(s_d>=20){
				cout<<"-1\n";
				return;
			}
			AQ.push_back(a_d);
			SQ.push_back(s_d);

			a.pop_back();
			s.pop_back();
		}
	}
	if(!a.empty()){
		cout<<"-1\n";
		return;
	}
	while(!s.empty()){
		int s_d = s.back()-'0';
		SQ.push_back(s_d);
		s.pop_back();
	}
	int carry=0;
	for(int i=0;i<SQ.size();i++){
		SQ[i]=(SQ[i]+carry);
		carry=0;
		if(SQ[i]>9){
			carry=1;
		}
		SQ[i]%=10;
	}
	if(carry){
		SQ.push_back(1);
	}
	reverse(SQ.begin(),SQ.end());
	ll sum=0;
	for(int i=0;i<SQ.size();i++){
		sum=sum*10 + SQ[i];
	}
	if( sum - num1 >=0){
		cout<<sum-num1<<endl;
	}
	else{
		cout<<"-1\n";
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
/*
6
17236 1106911
1 5
108 112
12345 1023412
1 11
1 20
6
3465 1106911
4 5
108 112
90007 1023412
10 11
1 20

3465
4
-1
90007
10
-1

*/