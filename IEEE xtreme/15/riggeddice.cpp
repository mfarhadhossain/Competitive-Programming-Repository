#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//ll n,m,target;
int a[1005],b[1005],n;
void solve(){
	cin >> n;
	int a_sum=0,b_sum=-1;
	for(int i=0;i<n;i++){
		cin >> a[i]>> b[i];
		if(a_sum==b_sum){
		    swap(a[i],b[i]);
		}
		a_sum+=a[i];
		b_sum+=b[i];
	}
	
	std::vector<int> alice(10),bob(10);
	for(int i=0;i<n;i++)
		alice[a[i]]++;
	for(int i=0;i<n;i++)
		bob[a[i]]++;
	double M = n*1.0/6 + 5.0*(1.0/6.0)*sqrt(n*5.0);
	// M>N/6+X∗(1/6)∗ sqrt(N∗5)
	if( alice[6]>M ) cout<<"1\n";
	else cout<<"2\n";
	//cout<<fixed<<setprecision(10)<<df1<<" "<<df2<<endl;
	//else if(df1>df2)cout<<"1\n";
	// else cout<<"2\n";
}
int main (){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}