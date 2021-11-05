#include <bits/stdc++.h>
using namespace std;
void print(vector<string>s){
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;
    }
}
int match(vector<string>image1,vector<string>image2){
    //cout<<"matching starts!\n"<<endl;
    int n = image1.size(),m = image1[0].size();
    int n2 = image2.size(),m2 = image2[0].size();
    int res=0,sz=n2*m2;
    for(int i=0;i+n2<n;i++){
        for(int j=0;j+m2<m;j++){
            int cnt=0;
            for(int k=0;k<n2;k++){
                for(int l=0;l<m2;l++){
                    if(image2[k][l]=='?'){
                        cnt++;
                    }
                    else if(image1[i+k][j+l]==image2[k][l])
                        cnt++;
                    else{
                        break;
                    }
                }
            }
            if(cnt==sz)
                res++;
        }
    }
    //cout<<"matching ends!\n"<<endl;
    return res;
}
void solve(){

   int r1,c1,r2,c2;
    cin >> r1 >> c1;
    vector<string> image1;
    for(int i=0;i<r1;i++){
        string tm;
        cin>>tm;
        image1.push_back(tm);
    }
    //print(flip_verticalNEW(image1));
    cin>>r2>>c2;
    //cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    
    vector<string>image2;
    for(int i=0;i<r2;i++){
        string tm;
        cin>>tm;
        image2.push_back(tm);
    }
    
   // cout<<"input ends!"<<endl;
    int res=0;

    res=max(res,match(image1,image2));
    cout<<res<<endl;
}
int main() {
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}