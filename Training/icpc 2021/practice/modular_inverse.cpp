#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int  main ()
{
	int a,b;cin>>a>>b;
	int q,r1,r2,r,t1,t2,t;
	r1 = a;
	r2 = b;
	t1 = 0;
	t2 = 1;
	
	while(r2>0){
		q = r1/r2;
		r=r1 - q*r2;
		r1=r2;
		r2=r;

		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	cout<<t1<<endl;
	return 0;
}