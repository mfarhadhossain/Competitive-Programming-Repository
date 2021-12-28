#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,res=0;cin>>n;
	vector<int> p(n),t(n);
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	int reuse1=0,reuse2=0,inc=0,dec=0;
	for(int i=0;i<n;i++){
		int df = abs(p[i]-t[i]);
		if(p[i]>t[i]){
			if(reuse1 >= df){
				dec+=reuse1-df;
			}
			else{
				inc+=df-reuse1;
				reuse1=df-reuse1;
			}
		}
		else if(p[i]<t[i]){

			if(reuse2 >= df){
				inc+=reuse2-df;
			}
			else{
				dec+=df-reuse2;
				reuse2=df-reuse2;
			}
		}
	}
	cout<<inc<<endl;
	cout<<dec<<endl;
	cout<<inc+dec<<endl;
	// while(true){
	// 	bool good=true;

	// 	int l=0,r=0,mn=1e9;

	// 	for(int i=0;i<n;i++){
	// 		if(p[i]<t[i]){
	// 			l=i;
	// 			good=false;
	// 			break;
	// 		}
	// 	}
	// 	if(good)break;

	// 	for(int i=l;i<n;i++){
	// 		if(p[i]<t[i]){
	// 			r=i;
	// 			mn = min(mn,t[i]-p[i]);
	// 		}
	// 		else{
	// 			break;
	// 		}
	// 	}
	// 	for(int i=l;i<=r;i++){
	// 		p[i]+=mn;
	// 	}
	// 	res+=mn;
	// }
	// while(true){
	// 	bool good=true;

	// 	int l=0,r=0,mn=1e9;

	// 	for(int i=0;i<n;i++){
	// 		if(p[i]>t[i]){
	// 			l=i;
	// 			good=false;
	// 			break;
	// 		}
	// 	}
	// 	if(good)break;

	// 	for(int i=l;i<n;i++){
	// 		if(p[i]>t[i]){
	// 			r=i;
	// 			mn = min(mn,p[i]-t[i]);
	// 		}
	// 		else{
	// 			break;
	// 		}
	// 	}
	// 	for(int i=l;i<=r;i++){
	// 		p[i]-=mn;
	// 	}
	// 	res+=mn;
	// }
	// cout<<res<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}