#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int diff(string A,string B){
	vector<int>fa(26),fb(26);
	for(int i=0;i<A.size();i++){
		fa[A[i]-'A']++;
	}
	for(int i=0;i<B.size();i++){
		fb[B[i]-'A']++;
	}
	int cnt=0;
	for(int i=0;i<26;i++){
		if(fa[i]!=fb[i])cnt++;
	}
	return cnt;
}
void solve() {
	int n;cin>>n;
	vector<string>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	vector< pair<int,  pair<string,string> > > ar;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ar.push_back({diff(v[i],v[j]),{v[i],v[j]}});
		}
	}
	sort(ar.begin(),ar.end());
	cout<<ar[0].second.first<<" "<<ar[0].second.second<<endl;
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