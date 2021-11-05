#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX=4e5+7;
int a[MAX];
void solve(){
    int N,X,p,k;
    cin >> N >> X >> p >> k;

    for(int i=1;i<=N;i++)cin>>a[i];
    sort(a+1,a+1+N);
    int cnt_a = 0 , cnt_b=0;

    for(int i=1;i<=p;i++){
        if(a[i]>X)cnt_a++;
    }
    for(int i=p;i<=N;i++){
        if(a[i]<X)cnt_b++;
    }
    if(p<k){
        if(a[p]<X)cout<<"-1\n";
        else if(a[p]==X)cout<<"0\n";
        else{
            // 1 theke p porjonto joto number ase jegula >X
            cout<<cnt_a<<endl;
        }
    }
    else if(p==k){
        if(a[p]==X)cout<<"0\n";
        else{
            if(a[p]<X){
                 //p theke N porjonto joto number ase jegula <X
                 cout<<cnt_b<<endl;
            }
            else{ // a[p]>X
                 //1 theke p porjonto joto number ase jegula >X
                 cout<<cnt_a<<endl;
            }
        }
    }
    else{
        if(a[p]>X)cout<<"-1\n";
        else if(a[p]==X)cout<<"0\n";
        else{
            // p theke n porjonto joto number ase jegula < X
            cout<<cnt_b<<endl;
        }
    }

}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
