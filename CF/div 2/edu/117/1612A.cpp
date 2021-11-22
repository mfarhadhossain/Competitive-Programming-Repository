#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
void solve(){
	int x,y;cin>>x>>y;
	int res_x,res_y,bad=1;
	int mid = (x+y);
	for(int i=0;i<=50;i++){
		for(int j=0;j<=50;j++){
			int dx1=abs(x-i);
			int dy1=abs(y-j);
			int dx2=abs(i-0);
			int dy2=abs(j-0);
			int d1=dx1+dy1;
			int d2=dx2+dy2;
			if(d1==d2 && 2*d1==mid){
				bad=0;
				res_x = i;
				res_y = j;
				break;
			}
		}
		if(bad==0)break;
	}
	if(bad==0){
		cout<<res_x<<" "<<res_y<<endl;
	}
	else{
		cout<<"-1 -1\n";
	}
}
int  main ()
{
	int t=1;cin>>t;
	for(int tc=1;tc<=t;tc++)
		solve();
    return 0;
}