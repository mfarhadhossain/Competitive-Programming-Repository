#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool ok(int i,int j,vector<int>&v,int n){
	map<int,int> cnt;
	for(int idx = i;idx<=j;idx++){
		cnt[v[idx]]++;
	}

	for(int idx=1;idx<=j-i+1;idx++){
		if(cnt[idx]==0)return false;
	}
	return true;
}
int calc(vector<int>&v,int n) {
	map<int,int> cnt;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int l = j - i + 1;
			if(ok(i,j,v,n)){
				cnt[l]=1;
			}
		}
	}
	return cnt.size();
}
int  main ()
{
	int n;cin>>n;
	vector<int>perm(n);
	for(int i=1;i<=n;i++){
		perm[i-1] = i;
	}
	do{
		for(int x:perm){
			cout<<x<<" ";
		}
		cout<<" gf sub = "<<calc(perm,n)<<endl;
		//cout<<endl;

	}while(next_permutation(perm.begin(),perm.end()));
	return 0;
}