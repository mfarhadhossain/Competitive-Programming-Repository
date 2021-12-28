#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;

	vector<int>p(n);

	for(int i=0;i<n;i++)
		cin>>p[i];

	string s;cin>>s;

	vector<pair<int,int>> liked,disliked;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			liked.push_back({p[i],i});
		}
		else{

			disliked.push_back({p[i],i});
		}
	}
	sort(liked.rbegin(),liked.rend());
	sort(disliked.rbegin(),disliked.rend());

	vector<int>res(n);
	int curr = n;
	for(int i=0;i<liked.size();i++){
		int id = liked[i].second;
		res[id] = curr--;
	}
	for(int i=0;i<disliked.size();i++){
		int id = disliked[i].second;
		res[id] = curr--;
	}
	for(int i=0;i<n;i++)cout<<res[i]<<' ';
	cout<<endl;
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