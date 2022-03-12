#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void print(vector<int>&a){
	for(int x:a){
		cout<<x<<" ";
	}
	cout<<endl;
}
bool possible(vector<int>&a){
	vector<int>ret;
	int n = a.size(),s=0;
	for(int i=0;i<n;i++){
		ret.push_back(a[i]);
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				s+=a[k];
			}
			if(s%n==0)return false;
		}
	}
	//print(ret);
	return true;
}
void solve() {
	int n;cin>>n;
	vector<int>ar(n);
	for(int i=0,inc=1;i<n;i++){
		ar[i] = n+inc;
		inc=ar[i]+inc+1;
		cout<<ar[i]<<' ';
	}
	cout<<endl;
	cout<<possible(ar)<<endl;
	//cout<<endl;
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