#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int grid[105][105];
void solve() {

}
int distance(int r,int c,int x,int y){
	return abs(r-x) + abs(c-y);
}
int  main ()
{
	int n,m;cin>>n>>m;



	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			grid[i][j] = max({distance(i,j,1,1),distance(i,j,n,m),distance(i,j,n,1),distance(i,j,1,m)});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<grid[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}