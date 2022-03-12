#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	ll n;cin>>n;

	if(n&1){
		ll res = n*(n-1);
		cout<<res<<endl;
	}
	else{

		ll res = n*(n+1);
		cout<<res<<endl;
	}
}

ll calc(vector<int>&v,int n) {
	ll res=0;
	for(int i=1;i<=n;i++){
		res = res + (i^v[i-1]);
	}
	return res;
}
void bit(int x){
	vector<int>v;

	while(x){
		v.push_back(x%2);
		x/=2;
	}
	x = 4-v.size();
	while(x){
		v.push_back(0);
		x--;
	}

	reverse(v.begin(),v.end());
	for(int x:v)cout<<x;
	cout<<endl;
}
int  main ()
{
	ll res=0,ret=0;
	int n;cin>>n;
	vector<int>perm(n),p;
	for(int i=1;i<=n;i++){
		perm[i-1] = i;
	}
	do{
		// for(int x:perm){
		// 	cout<<x<<" ";
		// }
		res = calc(perm,n);
		ret=max(ret,res);
		if(ret == res){
			p = perm;
		}
		//cout<<" score = "<<res<<endl;
		//cout<<endl;

	}while(next_permutation(perm.begin(),perm.end()));
	int i=1;
	for(int x:p){
		cout<<"xor = "<<(i^x)<<"\n";
		cout<<i<<": ";
		bit(i);
		cout<<x<<": ";
		bit(x);
		cout<<endl;
		i++;
	}

	cout<<ret<<endl;

ll ret2 = 0;
map<int,int>cnt;
	for(int i=1;i<=n;i++){
		int r = i^15;
		if(r>n or r==0)r = i^7;
		cnt[r]=1;
		
		ret2+= r;

	}
	cout<<ret2<<endl;
	return 0;
}