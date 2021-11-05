#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    ll A,B,n;
    cin>>A>>B>>n;
    vector<ll>attack(n),health(n+1);
    for(int i=0;i<n;i++){
            cin>>attack[i];
    }
    vector< pair<ll,ll> > V;
    for(int i=0;i<n;i++){
            cin>>health[i];
            V.push_back({attack[i],health[i]});
    }
    sort(V.begin(),V.end());


    for(int i=0;i<n;i++){
        attack[i] = V[i].first;
        health[i] = V[i].second;
    }
    for(int i=0;i<n;i++){
            ll need = health[i];
            ll fight = need/(A);

            if(need%A)fight++;


            ll turn1 = fight-1;
            ll turn2 = fight;

            ll point1 = turn1 * attack[i];
            ll point2 = turn2 * attack[i];
//
//            cout<<"for "<<i<<" th monster : ";
//            cout<<"fights = "<<turn2<<endl;
//
//            cout<<"before attack: ";
//            cout<<"hero  = "<<B<<" monster  = "<<health[i]<<endl;

            if( (B - point1)> 0 ){
                    B-=point2;
            }
            else{
                cout<<"NO\n";
                return;
            }
            health[i]-=A*turn2;
            //cout<<"after attack: ";
            //cout<<"hero  = "<<B<<" monster  = "<<health[i]<<endl;
            //if(B<=0)break;
    }
    cout<<"YES\n";
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}
