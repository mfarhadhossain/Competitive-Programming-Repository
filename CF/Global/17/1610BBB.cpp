#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
bool alreadysorted(vector<int>&a){
	vector<int>rev = a;
	reverse(rev.begin(),rev.end());
	return a==rev;
}
bool hahahoho(vector<int>&v,int x){
	vector<int>res;
	for(int y:v){
		if(y!=x){
			res.push_back(y);
		}
	}
	return alreadysorted(res);
}
void solve() {
	int n; cin>>n;
	vector<int>a(n);
	map<int,int> cnt;
	//vector<int>pos[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(alreadysorted(a) or cnt.size()<=2){
		cout<<"YES\n";
		return;
	}

	// vector<int>odd_f,vs(n+1);

	// for(int i=0;i<n;i++){
	// 	if(vs[a[i]])continue;

	// 	if(cnt[a[i]]&1)odd_f.push_back(a[i]);
	// }

	// if(odd_f.size()>2){
	// 	cout<<"NO\n";
	// 	return;
	// }

	set<int>bad;

	for(int i=0,j=n-1;i<n;i++,j--){
		if(a[i]!=a[j]){
			bad.insert(a[i]);
			bad.insert(a[j]);
		}
		if(bad.size()>10)break;
	}

	int kibepar=0;

	for(auto x:bad){
		kibepar=hahahoho(a,x);
		if(kibepar){
			cout<<"YES\n";
			return;
		}
	}

	cout<<"NO\n";
	return;
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