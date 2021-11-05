#include<bits/stdc++.h>
using namespace std;
void solve(){
	int N,X,Y;
	cin>>N>>X>>Y;
	N++;
	if(X<=Y*N)cout<<"YES\n";
	else cout<<"NO\n";
}
int main (){
	int t;cin>>t;
	while(t--)solve();
	return 0;
}