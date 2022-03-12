#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void gen(int idx,int cnt, vector<int>curr, vector<int>&ar){
	if(idx == ar.size()){
		if(cnt)return;
		map<int,int>mp;
		for(int i=0;i<curr.size();i++){
			cout<<curr[i]<<' ';
			mp[curr[i]]=1;
		}
		cout<<endl;
		for(int i=0;i<ar.size();i++){
			if(mp[ar[i]])continue;

			cout<<ar[i]<<' ';
		}
		cout<<endl;
		return;
	}
	gen(idx+1,cnt,curr,ar);
	curr.push_back(ar[idx]);
	gen(idx+1,cnt-1,curr,ar);
}
map< int, vector< pair<int,int>> > mmp;
void gen2(map<int,int> mp,int n,vector< pair<int,int>> vp){
	if(mp.size() == n){
		int res=0;
		for(auto x:vp){
			res+= (x.first&x.second);
			//cout<<x.first<<" "<<x.second<<endl;
		}
		//cout<<"k = "<<res<<endl;
		mmp[res] = vp;
		return;
	}
	for(int i=0;i<n;i++){
		if(mp[i])continue;
		mp[i]=1;
		for(int j=0;j<n;j++){
			if(mp[j])continue;
			//mp[i]=1;
			mp[j]=1;
			vp.push_back({i,j});
			gen2(mp,n,vp);
			vp.pop_back();
			mp.erase(j);
		}
		mp.erase(i);
	}
}
int  main ()
{

	// int n; cin >> n;

	// vector<int>ar(n);

	// for (int i = 0; i < n; i++) {
	// 	ar[i]=i;
	// }
	// map<int,int> mp;
	// vector< pair<int,int> >curr;
	// gen2(mp,n,curr);

	// for(auto xx:mmp){
	// 	auto x= xx.second;
	// 	cout<<"and sum "<<xx.first<<endl;
	// 	for(int i=0;i<x.size();i++){
	// 		auto y = x[i];
	// 		cout<<y.first<<" "<<y.second<<endl;
	// 	}
	// 	cout<<endl;
	// }

	for(int i=0;i<=7;i++){
		cout<<i<<": ";
		for(int j=0;j<=7;j++){
			if(i==j)continue;

			if( (i&j) == 0){
				cout<<j<<",";
			}
		}
		cout<<endl;
	}
	return 0;
}