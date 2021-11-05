#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e5;
typedef long long int ll;
ll lx[MAX+25],ly[MAX+25],hx[MAX+25],hy[MAX+25];
void solve(){
    int k;cin>>k;
    for(int i=0;i<k;i++)
        cin>>lx[i]>>ly[i]>>hx[i]>>hy[i];
    vector<ll>vx,vy;
    for(int i=0;i<k;i++){
        vx.push_back(lx[i]);
        vx.push_back(hx[i]);

        vy.push_back(ly[i]);
        vy.push_back(hy[i]);
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    int md = vx.size()/2;

    ll mn = 1e18,res_x=0,res_y=0;
    for(int j=0;j<min((int)vx.size(),10000);j++){
        ll d=0,x = vx[j],y = vy[j];
                for(int i=0;i<k;i++){

                    if(x>=lx[i] && x<=hx[i] && y>=ly[i] && y<=hy[i]){
                        d+=0;
                    }
                    else{
                       // L
                        if(x<lx[i]&&y>=ly[i]&&y<=hy[i]){
                            d+=abs(lx[i]-x);
                        }
                       // R
                        else if(x>hx[i]&&y>=ly[i]&&y<=hy[i]){
                            d+=abs(hx[i]-x);
                        }
                        //T
                        else if(y>hy[i]&&x>=lx[i]&&x<=hx[i]){
                            d+=abs(hy[i]-y);
                        }
                       // D
                        else if(y<ly[i]&&x>=lx[i]&&x<=hx[i]){
                            d+=abs(ly[i]-y);
                        }
                        else{
                            int mn_x = min(abs(lx[i]-x),abs(hx[i]-x));
                            int mn_y = min(abs(ly[i]-y),abs(hy[i]-y));
                            d+=mn_x+mn_y;
                        }
                    }
                }
                if(d<mn){
                    mn = d;
                    res_x= x;
                    res_y= y;
                }
                else if(d == mn){
                    if(x<res_x){
                        res_x = x;
                        res_y = y;
                    }
                    if(x==res_x && y<res_y){
                        res_x = x;
                        res_y = y;
                    }
                }

    }
//    int mn = 1e9,res_x=0,res_y=0;
//    for(int x=-100;x<=100;x++){
//        for(int y=-100;y<=100;y++){
//                int d=0;
//                for(int i=0;i<k;i++){
//
//                    if(x>=lx[i] && x<=hx[i] && y>=ly[i] && y<=hy[i]){
//                        d+=0;
//                    }
//                    else{
//                        L
//                        if(x<lx[i]&&y>=ly[i]&&y<=hy[i]){
//                            d+=abs(lx[i]-x);
//                        }
//                        R
//                        else if(x>hx[i]&&y>=ly[i]&&y<=hy[i]){
//                            d+=abs(hx[i]-x);
//                        }
//                        T
//                        else if(y>hy[i]&&x>=lx[i]&&x<=hx[i]){
//                            d+=abs(hy[i]-y);
//                        }
//                        D
//                        else if(y<ly[i]&&x>=lx[i]&&x<=hx[i]){
//                            d+=abs(ly[i]-y);
//                        }
//                        else{
//                            int mn_x = min(abs(lx[i]-x),abs(hx[i]-x));
//                            int mn_y = min(abs(ly[i]-y),abs(hy[i]-y));
//                            d+=mn_x+mn_y;
//                        }
//                    }
//                }
//                if(d<mn){
//                    mn = d;
//                    res_x= x;
//                    res_y= y;
//                }
//                else if(d == mn){
//                    if(x<res_x){
//                        res_x = x;
//                        res_y = y;
//                    }
//                    if(x==res_x && y<res_y){
//                        res_x = x;
//                        res_y = y;
//                    }
//                }
//        }
//    }
    cout<<res_x<<" "<<res_y<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    for(int tc=1;tc<=t;tc++){
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}

