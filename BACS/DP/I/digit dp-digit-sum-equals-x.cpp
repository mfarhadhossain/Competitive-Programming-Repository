// Digit DP-1
// Given A,B and X
//print how many integers between A and B 
//have a digit sum equal to X
// 1<=A<=B<=1e9, 1<=X<=1e5
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
string str,a,b;
int x,dp[15][2][91];

int go(int idx,int isSmall,int digitsum){
	//cout<<idx<<" "<<isSmall<<" "<<digitsum<<endl;
	if(idx>=str.size())
		return digitsum==x;
	if(dp[idx][isSmall][digitsum]!=-1)
		return dp[idx][isSmall][digitsum];
	int lo=0,hi=str[idx]-'0',res=0;
	for(int i=lo;i<=hi;i++){
		int newSmall = isSmall|(1<hi);
		res+=go(idx+1,newSmall,digitsum+i);
	}
	return dp[idx][isSmall][digitsum]=res;
}
int  main ()
{
	memset(dp,-1,sizeof dp);
	cin>>a>>b>>x;
	str=a;
	int res1 = go(0,0,0);
	str=b;
	memset(dp,-1,sizeof dp);
	int res2 = go(0,0,0);
	cout<<"res1 = "<<res1<<endl;
	cout<<"res2 = "<<res2<<endl;
	cout<<res2-res1<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
    return 0;
}