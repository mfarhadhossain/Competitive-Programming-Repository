#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
bool simulate(vector<int>p,int idx,vector<bool>v,int turn){
    v[idx]=1;


    if(turn){ // B
        int res=0;
        if(idx-1 >=0){
                if(v[idx-1]>v[idx])res= simulate(p,idx-1,v,turn^1);

        }
        if(res==0)return res;
        if(idx+1 < p.size()){
                if(v[idx+1]>v[idx])res= simulate(p,idx+1,v,turn^1);
                else return 1;
        }
        return res;
    }
    else{
        int res=0;
        if(idx-1 >=0){
                if(v[idx-1]<v[idx])res= simulate(p,idx-1,v,turn^1);
        }
        if(res==1)return res;
        if(idx+1 < p.size()){

                if(v[idx+1]<v[idx])res|= simulate(p,idx+1,v,turn^1);

        }
        return res;
    }
}
int main (){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

int n;cin>>n;
    vector<int>p(n),ar(n),suf(n);


    for(int i=0;i<n;i++)cin>>p[i];

    ar[0]=1;
    suf[n-1]=1;
    for(int i=1;i<n;i++){
        if(p[i]>p[i-1]){
            ar[i]=1+ar[i-1];
        }
        else ar[i]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(p[i]>p[i+1]){
            suf[i]=1+suf[i+1];
        }
        else suf[i]=1;
    }
    int res=0;
    for(int i=1;i<n-1;i++){
        if(abs(suf[i+1]-ar[i-1])>2)res++;
    }
    cout<<res<<endl;
    return 0;
}



