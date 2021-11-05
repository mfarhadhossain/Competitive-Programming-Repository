#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ff first
#define ss second
typedef long long int ll;
typedef pair<int,int> pii;
void solve(){
    int n;cin>>n;
    vector< pair<pair<int,int> ,int> >v_w(n),v_h(n);
    vector<int>w(n),h(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>h[i];

        v_w.push_back({{w[i],h[i]},i+1});
        v_w.push_back({{h[i],w[i]},i+1});
        v_h.push_back({{h[i],w[i]},i+1});
        v_h.push_back({{w[i],h[i]},i+1});
    }
    sort(v_w.begin(),v_w.end());
    sort(v_h.begin(),v_h.end());
    vector<int>res(n,-1);

    for(int i=0;i<n;i++){
            // w-1,h-1
            pair<pair<int,int> ,int> x,y;
            x = {{w[i],h[i]},-1};
            y = {{h[i],w[i]},-1};

            int pos = lower_bound(v_w.begin(),v_w.end(),x)-v_w.begin();

            int good = 0;

            cout<<"khujtisi ("<<w[i]<<" , "<<h[i]<<"):\n";
            for(int j=max(0,pos-10);j<=min(n-1,pos+10);j++){
                cout<<"paisi ("<<v_w[j].ff.ff<<" , "<<v_w[j].ff.ss<<")!\n";
                if(v_w[j].ff.ff<w[i]&&v_w[j].ff.ss<h[i]){
                    res[i]=v_w[j].ss;
                    good = 1;
                    break;
                }

                if(v_w[j].ff.ff<h[i]&&v_w[j].ff.ss<w[i]){
                    res[i]=v_w[j].ss;
                    good = 1;
                    break;
                }
            }
            if(good)continue;

            pos = lower_bound(v_h.begin(),v_h.end(),y)-v_h.begin();

            //int good = 0;

            for(int j=max(0,pos-10);j<=min(n-1,pos+10);j++){
                if(v_h[j].ff.ff<h[i]&&v_h[j].ff.ss<w[i]){
                    res[i]=v_w[j].ss;
                    good = 1;
                    break;
                }

                if(v_h[j].ff.ff<w[i]&&v_h[j].ff.ss<h[i]){
                    res[i]=v_w[j].ss;
                    good = 1;
                    break;
                }
            }
            if(good==0)res[i]=-1;
    }
    for(int x:res)cout<<x<<" ";
    cout<<endl;
}
int main (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}
