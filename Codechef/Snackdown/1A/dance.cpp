#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lcm(ll x,ll y){
	ll g = __gcd(x,y);
	return x*y/g;
}
void solve(){
	ll X,Y;
	cin>>X>>Y;
	cout<<X*2<<" "<<lcm(Y*X-1,Y*X)<<endl;
}
int main (){
	int t;cin>>t;
	while(t--)solve();
	return 0;
}