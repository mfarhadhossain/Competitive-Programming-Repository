#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	string s;cin>>s;
	int n = s.size();
	vector<int>cnt(30);
	for(int i=0;i<n;i++){
		cnt[s[i]-'a']++;
	}

	for(int i=0;i<26;i++){
		if(cnt[i]==2){
			cout<<(char)(i+'a');
			cout<<(char)(i+'a');
			cnt[i]=0;
		}
	}
	for(int i=0;i<26;i++){
		if(cnt[i]==1){
			cout<<(char)(i+'a');
			cnt[i]--;
		}
	}
	cout<<"\n";
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