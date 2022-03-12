#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, k; cin >> n >> k;
	int res = 0;
	for (int i = 0, j = 1; i < n; i += 2, j += 2) {
		res += (i & j);
	}
	if (k > res) {
		cout << "-1\n";
		return;
	}

	n--;

	cout << n << " " << k << endl;

	vector<int> taken(n + 10), rem;

	taken[n] = 1;
	taken[k] = 1;
	for (int i = 0; i <= n; i++) {
		if (taken[i])continue;
		rem.push_back(i);
	}

	if(k == n){
		// two odd

		vector<int>odd;
		int cnt=2;
		for(int x:rem){
			if(x&1){
				odd.push_back(x);
				cnt--;
			}
			if(cnt==0)break;
		}
		cout<<odd[0]<<" "<<odd[1]<<endl;

		taken[odd[0]]=1;
		taken[odd[1]]=1;
		
		for(int x:rem){
			if(taken[x])continue;
			int y = (n^x);
			cout<<x<<" "<<y<<endl;
			taken[x]=1;
			taken[y]=1;
		}

	}
	else{

		for(int x:rem){
			if(taken[x])continue;
			int y = (n^x);
			cout<<x<<" "<<y<<endl;
			taken[x]=1;
			taken[y]=1;
		}
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