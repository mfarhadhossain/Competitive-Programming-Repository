#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n, x, y; cin >> n >> x >> y;

	string s; cin >> s;

	ll cnt = 0, c = 1;
	vector<ll>A;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			cnt++;
		}
		else if (s[i] == '0') {
			if (cnt) A.push_back(cnt);
			cnt = 1;
			c++;
		}
	}

	if (cnt) A.push_back(cnt);

	// for (int x : A)cout << x << " ";
	// cout << endl;
	// for (int x : B)cout << x << " ";
	// cout << endl;

	ll curr_x = 0 , curr_y=0,i=0;

	while(i<A.size()){
		if(i%2==0)
		curr_x+=A[i++];
		else curr_y+=A[i++];
	}
	if(abs(x-curr_x)%2==0 && abs(y-curr_y)%2==0){
		cout<<"YES\n";
		return;
	}
   curr_x = 0 , curr_y=0,i=0;

	while(i<A.size()){
		if(i%2)
		curr_x+=A[i++];
		else curr_y+=A[i++];
	}
	if(abs(x-curr_x)%2==0 && abs(y-curr_y)%2==0){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
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