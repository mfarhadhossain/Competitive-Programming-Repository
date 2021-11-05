#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX=4e5+7;
void solve(){
    ll n,k;cin>>n>>k;
    ll ar[n+2],suffix_sum[n+2];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    sort(ar+1,ar+1+n);
    suffix_sum[n+1]=0;
    for(int i=n;i>=1;i--){
        suffix_sum[i]=suffix_sum[i+1]+ar[i];
    }

//    for(int i=1;i<=n;i++){
//        cout<<ar[i]<<' ';
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++){
//        cout<<suffix_sum[i]<<' ';
//    }
//    cout<<endl;

    int res_cnt=1,res_min=ar[1];
    for(int i=1;i<=n;i++){
            ll l = 1 , r = i,ret=0;
            while(r-l>=10){

                ll mid = (l+r)/2;

                int elements = i-mid+1;
                ll sum = elements*ar[i];
                ll curr_sum = suffix_sum[mid] -suffix_sum[i+1];
                if(curr_sum + k >= sum){
                        r = mid;
                }
                else l = mid+1;
            }
            for(int j=max(1LL,l-10);j<=min(n,r+10);j++){
                int elements = i-j+1;
                ll sum = elements*ar[i];
                ll curr_sum = suffix_sum[j] -suffix_sum[i+1];
                if(curr_sum + k >= sum){
                        ret = elements;
                        break;
                }
            }
            if(ret>res_cnt){
                res_cnt=ret;
                res_min=ar[i];
            }
    }

    cout<<res_cnt<<" "<<res_min<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}

