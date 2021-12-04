#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
int calculate_descent(vector<int>&p){
	int cnt=0;
	for(int i=1;i<p.size();i++){
		if(p[i]<p[i-1])cnt++;
	}
	return cnt;
}
void solve() {
	int n;cin>>n;
	vector<int>p(n),res;
	for(int i=0;i<n;i++)
		cin>>p[i];
	int des1 = calculate_descent(p),i=0;
	do{
		if(i&&des1==calculate_descent(p)){
			res=p;
			break;
		}
		i++;
	}while(next_permutation(p.begin(),p.end()));

	if(res.empty()){
		cout<<"-1\n";
	}
	else{
		for(int i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<p[i];
		}
		cout<<endl;
	}
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}