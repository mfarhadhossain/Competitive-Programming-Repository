#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector<int>ar;
void solve() {
	string b="",a,s;cin>>a>>s;
	reverse(a.begin(),a.end());
	reverse(s.begin(),s.end());
	int i=0,j=0;
	for(i=0,j=0;i<a.size()&&j<s.size();i++,j++){
		int a_d = (a[i]-'0');
		int s_d = (s[j]-'0');
		if(s_d>=a_d){
			int b_d = s_d-a_d;
			char b_c = (char)(b_d+'0');
			b.push_back(b_c);
		}
		else{
			if(s.size()<=j+1){
				cout<<"-1\n";
				return;
			}
			else{
				s_d = (s[j+1]-'0')*10 + s_d;
				if(s_d - a_d >9){
					cout<<"-1\n";
					return;
				}
				int b_d = s_d-a_d;
				char b_c = (char)(b_d+'0');
				b.push_back(b_c);
				j++;
			}
		}
	}
	// debug
	if(i<a.size()){
		cout<<"-1\n";
		return;
	}
	while(j<s.size()){
		int s_d = (s[j]-'0');
		int b_d = s_d;
		char b_c = (char)(b_d+'0');
		b.push_back(b_c);
		j++;
	}
	while(b.size()&&b.back()=='0'){
		b.pop_back();
	}
	reverse(b.begin(),b.end());
	cout<<b<<endl;
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