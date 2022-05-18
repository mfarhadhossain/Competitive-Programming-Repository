#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout<<x<<endl
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool badword(string x) {
	vector<int> pos[26];
	int i = 0;
	for (auto y : x)
		pos[y - 'A'].push_back(i++);
	int bad = 0;
	for (int i = 0; i < 26; i++) {
		if (pos[i].size() == 1)
			continue;


		for (int j = 1; j < pos[i].size(); j++) {
			if (pos[i][j - 1] + 1 != pos[i][j])bad |= 1;
		}
	}
	//cout<<x<<" "<<bad<<endl;
	return bad;
}
void solve() {
	int n; cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
	}

	string res = "IMPOSSIBLE";
	for (int i = 0; i < n; i++) {
		if (badword(v[i])) {
			cout << res << endl;
			return;
		}
	}
	cout<<"loop start!\n";
    vector<string> curr;
	while(true){
		int bad=0;
		cout<<"before: ";
		for (int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
		}
		cout<<endl;

		for (int i = 0; i < v.size(); i++) {

			// ith block being the top block
			vector<bool>vs( (int)v.size(), false);

			for (int j = 0; j < v.size(); j++) {
				if (vs[j])continue;

				if (v[j][0] == v[i].back()) {
					v[i] += v[j];
					vs[j] = true;
					break;
				}
			}
			for (int j = 0; j < v.size(); j++) {
				if(vs[j]==0){
					curr.push_back(v[j]);
					bad=1;
				}
			}
		}
		v = curr;
		if(bad==0)break;
	}
	cout<<"loop end!\n";

	for(auto x:v)
		res+=x;
	if (badword(res)) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << res << endl;
}
int  main ()
{

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
