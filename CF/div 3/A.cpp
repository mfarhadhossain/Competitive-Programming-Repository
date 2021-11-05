#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 5007;
typedef long long int ll;
int a[77][77],n,m,k,can;
int solve(int r,int cnt,int sum){
    if(r==n){
        if(sum%k==0)return sum;
        return 0;
    }
    int res=0;
    for(int i=1;i<=m;i++){

        if(cnt<can){
            res = max(res,solve(r+1,cnt,sum));
            res = max(res,solve(r+1,cnt+1,sum+a[r][i]));
            cnt++;
        }
    }
    return res;
}
int main (){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    cin>>n>>m>>k;
    can = m/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    cout<<solve(1,0,0);
    //main();
    return 0;
}
