#include <bits/stdc++.h>
using namespace std;
int main (){
	int n,m,t;
	cin>>t;
	while(t--){
	cin>>n>>m;

	string command;
	cin>>command;
	int x=0,y=0,res_x1=0,res_y1=0,res_x2=1,res_y2=1;
	int mx_x=0,mx_y=0,l=0,r=0,d=0,u=0;
	int mn_x = 0,mn_y=0;
	for(int i=0;i<command.size();i++){
		if(command[i]=='L')l++;
		if(command[i]=='R')r++;
		if(command[i]=='D')d++;
		if(command[i]=='U')u++;

		mx_x = max(mx_x,r);
		mn_x = max(mn_x,l);

		mx_y = max(mx_y,d);
		mn_y = max(mn_y,u);

		if(mx_x<mn_x){
			res_y1 = 1+mn_x;
		}
		else if(mx_x>mn_x){
			res_y1 = m-mx_x;
		}
		else{
			res_y1 = 1+mn_x;
		}
		if(mx_y<mn_y){
			res_x1 = 1+mn_y;
		}
		else if(mx_y>mn_y){
			res_x1 = n-mx_y;
		}
		else{
			res_x1 = 1+mn_y;
		}

		cout<<i<<" "<<res_x1<<" "<<res_y1<<endl;

		if(res_x1>=1&&res_x1<=n&&res_y1>=1&&res_y1<=m){
			res_x2=res_x1;
			res_y2=res_y1;
		}
		else{
			break;
		}
	}
	cout<<res_x2<<" "<<res_y2<<endl;
}
	return 0;
}