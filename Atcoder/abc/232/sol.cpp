#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
inline int StringToInt(string a)
{
    int num;
    stringstream aw(a);
    aw>>num;
    return num;
}

void solve() {
	int n,cnt=0,tot=0;cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		//cout<<s<<endl;
		if(s.back()=='*'){
			s.pop_back();
		}
		else{
			cnt++;
		}
		tot+=StringToInt(s);

	}
	if(cnt==0){
		cout<<"-1\n";
	}
	else{
		cout<<tot/cnt<<endl;
	}
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cout<<"Case "<<tc<<": ";
		solve();
	}
	return 0;
}