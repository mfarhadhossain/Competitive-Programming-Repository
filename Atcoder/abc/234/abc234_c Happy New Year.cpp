#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e8;
void solve() {
	ll k;cin>>k;
	string res="";
	while(k){
		if(k&1){
			res.push_back('2');
		}
		else{
			res.push_back('0');
		}
		k/=2;
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
}
int  main ()
{

	freopen("out.txt","w",stdout);
	cout<<1<<endl;
	cout<<100<<endl;
	ll pr = 0;
	vector<ll>ar(101);
	for(int i=0;i<100;i++){
		ll curr = pr+(rand()%MOD)+1;
		cout<<curr<<" ";
		pr = curr;
		ar[i]=curr;
	}
	cout<<endl;
	for(int i=0;i<100;i++){
		ll curr = (rand()%ar[i])+1;
		cout<<curr<<" ";
		//pr = curr;
	}
	cout<<endl;
	return 0;
}