#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
//int a[MAX],b[MAX];
int LIS(vector<int>&A){
    vector<int>B;
    B.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        //auto it = lower_bound(B.begin(),B.end(),A[i])-B.begin(); // increasing
        auto it = upper_bound(B.begin(),B.end(),A[i])-B.begin(); // Non-Decresing
        if(it>=B.size()){
            B.push_back(A[i]);
        }
        else B[it]=A[i];
    }
    return B.size();
}

void solve() {
	int n,m;cin>>n>>m;

    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    // int i = 0 , j = 0;
    // while(i<n || j<m){
    //     if(i<n&&j<m){
    //         if(a[i]<b[j]){
    //             merged.push_back(a[i]);
    //             i++;
    //         }
    //         else{
    //             merged.push_back(b[j]);
    //             j++;
    //         }
    //     }
    //     else if(i<n && j>=m){
    //             merged.push_back(a[i]);
    //         i++;
    //     }
    //     else if(j<m && i>=n){

    //             merged.push_back(b[j]);
    //         j++;
    //     }
    // }
    cout<<LIS(a)+LIS(b)<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}