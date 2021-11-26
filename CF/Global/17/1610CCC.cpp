#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
bool fun(vector<int>&a,vector<int>&b,int tot,int n){
	//cout<<"for "<<tot<<": ";
	int rich = tot-1, poor=0;
	int rich_hi = 0, poor_hi = tot-1;

	int ok=0;
	for(int i=0;i<n;i++){
		if(a[i]>=rich && b[i]>=poor){
			ok++;
			rich--;
			poor++;
		}
	}
	return ok>=tot;
}
void solve() {
	int n; cin>>n;
	vector<int>a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		b[i]=min(b[i],i);
		a[i]=min(a[i],n-(i+1));
	}
	int lo=1,hi=n;
	while(hi-lo>5){
		int mid = (lo+hi)/2;

		if(fun(a,b,mid,n)){
			lo=mid;
		}
		else{
			hi=mid-1;
		}
	}
	int res=1;
	for(int i=max(1,lo-10);i<=min(n,hi+10);i++){
		if(fun(a,b,i,n)){
			res=max(res,i);
		}
	}
	cout<<res<<endl;
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