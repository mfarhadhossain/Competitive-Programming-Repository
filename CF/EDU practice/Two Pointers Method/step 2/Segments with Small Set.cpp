#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;
int a[MAX],cnt[MAX];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,k;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    long long res=0,distinct=0;

    for(int r=0,l=0;r<n;r++){
        cnt[a[r]]++;
        if(cnt[a[r]]==1){
            distinct++;
            if(distinct<=k){
                res+=(distinct);
            }
        }
        else{
            if(distinct<=k){
                res+=(distinct-1);
            }
        }
        while(distinct>k){
            cnt[a[l]]--;
            if(cnt[a[l]]==0){
                distinct--;
            }
            l++;
//            if(distinct<=k){
            res+=1;
            //}
        }

    }

    cout<<res<<endl;

    return 0;
}
