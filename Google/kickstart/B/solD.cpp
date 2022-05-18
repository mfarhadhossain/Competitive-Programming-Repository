#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
#define PI acos(-1.0)
string grid[205];//res;
int n, m;
bool validMICRO(int i,int j){
	return i>=1&&i<=2&&j>=1&&j<=2;
}
bool valid(int i,int j){
	return i>=1&&i<=n&&j>=1&&j<=m;
}
void dfs(int x,int y,int i,int j,int par_x,int par_y,string res){
	if(x==1&&y==1&&par_x!=-1&&par_y!=-1){
		return;
	}
	if(validMICRO(i,j)==0 or valid(x,y)==0){
		res.pop_back();
		return;
	}
	if(grid[x][y]=='#'){
		res.pop_back();
		return;
	}
	// R
	if(i==1&&j==1){
		dfs(x,y,i,j+1,par_x,par_y,res+"E");
	}
	if(i==1&&j==2){

		dfs(x,y+1,1,1,x,y,res+"E");	
	}
	if(i==2&&j==1){
		
		dfs(x,y,i,j+1,par_x,par_y,res+"E");
	}
	if(i==2&&j==2){
		
		dfs(x,y+1,2,1,x,y,res+"E");
	}
	// D
	if(i==1&&j==1){
		dfs(x,y,i+1,j,par_x,par_y,res+"E");
	}
	if(i==1&&j==2){

		dfs(x,y+1,1,1,par_x,par_y,res+"E");	
	}
	if(i==2&&j==1){
		
		dfs(x,y,i,j+1,par_x,par_y,res+"E");
	}
	if(i==2&&j==2){
		
		dfs(x,y+1,2,1,par_x,par_y,res+"E");
	}
}
void solve() {
	string res="";

	cin >> n >> m;
	for (int i = 1; i <= n; i++){

		cin >> grid[i];
		grid[i] = "#" + grid[i];
	}
	dfs(1,1,1,1,-1,-1,-1,-1);
	cout<<res<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ":";
		solve();
	}
	return 0;
}