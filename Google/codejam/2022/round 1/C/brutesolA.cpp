#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool badword(string x){
	vector<int> pos[26];
	int i=0;
	for(auto y:x)
		pos[y-'A'].push_back(i++);
	int bad=0;
	for(int i=0;i<26;i++){
		if(pos[i].size()==1)
			continue;


		for(int j=1;j<pos[i].size();j++){
			if(pos[i][j-1]+1 !=pos[i][j])bad|=1;
		}
	}
	//cout<<x<<" "<<bad<<endl;
	return bad;
}
void solve() {
	int n; cin >> n;
	vector<string> v;
	vector<int>p;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
		p.push_back(i);
	}
	string res = "IMPOSSIBLE";
	do{
		string ret="";

		for(int i=0;i<p.size();i++){
			ret+=v[p[i]];
		}
		if(badword(ret)==0){
			res=ret;
			break;
		}
	}while(next_permutation(p.begin(),p.end()));
	
	// if(badword(res)){
	// 	cout<<"IMPOSSIBLE\n";
	// 	return;
	// }
	cout<<res<<endl;
}
int  main ()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}