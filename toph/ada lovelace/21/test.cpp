#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
const int MAX = 1e5 + 10;
void print(multiset< pair<ll,ll> >X){
	for(auto x:X){
		cout<<(x.first)<<" "<<x.second<<endl;
	}
}
void printA(multiset< pair<ll,ll>, greater<pair<ll,ll>>> X){
	for(auto x:X){
		cout<<(x.first)<<" "<<x.second<<endl;
	}
}
int  main ()
{
	
	multiset< pair<ll,ll> > bob;
	multiset< pair<ll,ll>, greater<pair<ll,ll>> > alice;
	bob.insert({200,2});
	bob.insert({200,0});
	bob.insert({10,4});
	bob.insert({10,6});

	alice.insert({200,-2});
	alice.insert({200,-0});
	alice.insert({10,-4});
	alice.insert({10,-6});

	print(bob);
	printA(alice);
	return 0;
}