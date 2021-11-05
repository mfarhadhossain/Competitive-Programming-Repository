#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5 + 7;
int a[15][15];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void solve(){
    int n,m,sum=0;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum+=a[i][j];
        }
    }
    int it=0,mx=sum;
    while(it<100){
        int mn = 0,id_i=0,id_j=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]<mn){
                    mn = a[i][j];
                    id_i=i;
                    id_j=j;
                }
            }
        }
        for(int k=0;k<4;k++){
            int xx = dx[k] + id_i;
            int yy = dy[k] + id_j;

            a[xx][yy]*=-1;
            a[id_i][id_j]*=-1;
            sum=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    sum+=a[i][j];
                }
            }
            a[xx][yy]*=-1;
            a[id_i][id_j]*=-1;
            mx=max(mx,sum);
        }
        it++;
    }
    cout<<mx<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}
