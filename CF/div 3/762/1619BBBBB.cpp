#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector<int>ar;
void solve() {
	int n;cin>>n;
	int pos = upper_bound(ar.begin(),ar.end(),n)-ar.begin();
	int sz = ar.size(),res=0;
	for(int i = max(0,pos-10);i<min(sz,pos+10);i++){
		if(ar[i]<=n){
			res=i+1;
		}
	}
	cout<<res<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int sq = sqrt(1000000007);
	unordered_map<int,int>m;
	for(int i=1;i<=sq;i++){
		int x = i*i;
		ar.push_back(x);
		m[x]=1;
	}
	for(int i=1;i<=1000;i++){
		int x = i*i*i;
		if(m[x]==0)
		ar.push_back(x);
		m[x]=1;
	}
	sort(ar.begin(),ar.end());
	
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}