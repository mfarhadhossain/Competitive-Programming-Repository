#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool isprime[217];
int  main ()
{
	isprime[1] = 0;
	isprime[2] = 1;
	for(int i=3;i<=207;i+=2){
		int p=1;
		for(int j=2;j<i;j++){
			if(i%j==0){
				p=0;
				break;
			}
		}
		if(p){
			isprime[i] = 1;
		}
	}

	int a,b,c,d;
	cin>>a>>b>>c>>d;


	for(int i=a;i<=b;i++){
		int takahashi = 1;
		for(int j=c;j<=d;j++){

			int sum = i+j;
			if(isprime[sum]){
				takahashi = 0;
				break;
			}
		}
		if(takahashi){
			cout<<"Takahashi\n";
			return 0;
		}
	}
	cout<<"Aoki\n";
	return 0;
}