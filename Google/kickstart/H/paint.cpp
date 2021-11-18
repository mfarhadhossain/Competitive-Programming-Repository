#include<bits/stdc++.h>
using namespace std;
struct color{
	int red,blue,yellow;
	color(){
		red=0,blue=0,yellow=0;
	}
	color(int r,int b,int y){
		red=r,blue=b,yellow=y;
	}
};
color fun(char ch){
	if(ch=='R')return color(1,0,0);
	if(ch=='B')return color(0,1,0);
	if(ch=='Y')return color(0,0,1);
	if(ch=='O')return color(1,0,1);
	if(ch=='A')return color(1,1,1);
	return color(0,1,1);
}
int solve(){
	int n;cin>>n;
	string s;cin>>s;

	vector< color > v;

	for(int i=0;i<n;i++){
		v.push_back(fun(s[i]));
	}
	vector<int>cnt(n+5);
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			
		}
	}
}
int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;cin>>t;
	for(int tc=1;tc<=t;tc++){
		cout<<"Case #"<<tc<<": "<<solve()<<endl;
	}
	return 0;
}