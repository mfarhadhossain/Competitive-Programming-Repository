#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	set<int>s;
	for(int i=0;i<n;i++){
		if(ar[i]==ar[i+1]){
			s.insert(ar[i]);
		}
	}
	if(s.size()==0){
		cout<<"0\n";
		return;
	}
	if(s.size() == 1){
		int same=1;
		for(int i=0;i<n;i++){
			if(ar[i]==ar[i+1]){
				same++;
			}
		}

		if(same == 2){
			cout<<"0\n";
		}
		else if(same == 3){
			cout<<"1\n";
		}
		else{
			cout<<same-3<<endl;
		}
	}
	else{
		int pos_L = 0;
		int pos_R = 0;
		for(int i=0;i<n+1;i++){
			if(ar[i]==ar[i+1]){
				pos_L = i+1;
				break;
			}
		}
		for(int i=n-1;i>pos_L;i--){
			if(ar[i]==ar[i-1]){
				pos_R = i-1;
				break;
			}
		}
		cout<<pos_R-pos_L<<endl;
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