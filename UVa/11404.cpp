// how to print dp solution ?

#include<bits/stdc++.h>
using namespace std;
#define end "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
int dp[1001][1001];
pair<int,int> nxt[1001][1001];
int go(int l, int r, string &s) {
	if (l > r)return 0;
	if (l == r){
		nxt[l][r]={l,r};
		return dp[l][r] = 1;
	}
	if (dp[l][r] != -1)
		return dp[l][r];
	int ret = 0;
	if (s[l] == s[r]) {
		nxt[l][r]=make_pair(l+1,r-1);
		ret = 2 + go(l + 1, r - 1, s);
	}
	else {
		int ret1 = go(l + 1, r, s);
		int ret2 = go(l, r - 1, s);
		if(ret1>ret2){
			nxt[l][r]=make_pair(l+1,r);
		}
		else if(ret2>ret1){

			nxt[l][r]=make_pair(l,r-1);
		}
		else{
			if(s[l]<s[l+1]){
				nxt[l][r]=make_pair(l,r-1);
			}
			else{
				nxt[l][r]=make_pair(l+1,r);
			}
		}
		ret=max(ret1,ret2);
	}
	return dp[l][r] = ret;
}
void solve(string &s) {
	if(s.size()<=1){
		cout<<s.size()<<"\n";
		return;
	}
	memset(dp, -1, sizeof dp);
	cout<<go(0, (int)s.size() - 1, s)<<endl;
	int l=0,r=s.size()-1;
	string res="";
	while(l!=r){
	
		cout<<l<<" "<<r<<endl;
		l=nxt[l][r].first;
		r=nxt[l][r].second;
	}
	cout<<"done!\n";
}
int  main ()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	while(cin>>s){
		solve(s);
	}
	return 0;
}