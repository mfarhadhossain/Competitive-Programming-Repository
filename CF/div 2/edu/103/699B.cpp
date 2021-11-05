#include<bits/stdc++.h>
using namespace std;
const int MAX = 107;
int h[MAX];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>h[i];
    h[n]=h[n-1];
    while(k>0){
            int bad=1;
            for(int i=0;i<n;i++){
                if(h[i]<h[i+1]){

                        bad=0;
                        k--;
                        h[i]++;
                        if(k<=0){
                            cout<<i+1<<"\n";
                            return;
                        }
                        break;
                }

            }
            if(bad){cout<<"-1\n";return;}

            //for(int i=0;i<n;i++)cout<<h[i]<<" ";
            //cout<<endl;
    }
    cout<<"-1\n";
}
int main (){
ios_base::sync_with_stdio(false);
cin.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}
/*
4
4 1
4 1 2 3
4 2
4 1 2 3
4 3
4 1 2 3
4 4
4 1 2 3
*/
