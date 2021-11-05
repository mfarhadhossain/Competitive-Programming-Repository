#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
string dic="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int hamming(string a,string b){
    int xd=0;
    for(int i=0,j=0;i<a.size();i++,j++){
        if(a[i]!=b[j])xd++;
    }
    return xd;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<string>V;
    map<string,int>cnt;
    map<string,int>vs;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        vs[s]=1;
        V.push_back(s);
        string temp=s;

        for(int j=0;j<(int)s.size();j++){
                if(s[j]=='-')continue;

                char v=temp[j];
                temp[j]='a';
                cnt[temp]=1;
                temp[j]=v;
        }
    }
    int res=0;
    for(int i=0;i<n;i++){ // 10^5
        string temp=V[i];
        for(int j=0;j<(int)V[i].size();j++){
            char v=temp[j];
            temp[j]='a';
            if(cnt[temp])res+=vs[temp];
            temp[j]=v;
        }
    }
    //cout<<res<<endl;
    cout<<res/2<<endl;
    return 0;
}
