#include <bits/stdc++.h>
using namespace std;
vector<string> flip_horizontal(vector<string>v){
    //vector<string>temp = v;
    //cout<<"flip_horizontal starts!"<<endl;
    for(int i=0;i<v.size();i++)
        reverse(v[i].begin(),v[i].end());

    //cout<<"flip_horizontal ends!"<<endl;
    return v;
}
vector<string> flip_vertical(vector<string>v){
    //vector<string>temp = v;


   // cout<<"flip_vertical starts!"<<endl;
    for(int i=0;i<v[0].size();i++){
        for(int j=0,k=v.size()-1;j<v.size()/2;j++,k--){
            swap(v[j][i],v[k][i]);
        }
    }

   // cout<<"flip_vertical ends!"<<endl;
    return v;
}
vector<string> flip_verticalNEW(vector<string>v){
    int n = v.size(),m = v[0].size();

    //vector<string>temp=v;
    for(int i=0;i<m;i++){
        string haha="";
        for(int j=0;j<n;j++){
            haha.push_back(v[j][i]);
        }
        reverse(haha.begin(),haha.end());

        for(int j=0;j<n;j++){
            v[j][i]=haha[j];
        }
    }
    return v;
}
vector<string> rotate_clockNEW(vector<string>v){
    int n = v.size(),m = v[0].size();

    vector<string>temp(m);
    for(int i=0;i<m;i++){
        string haha="";
        for(int j=n-1;j>=0;j--){
            haha.push_back(v[j][i]);
        }
        temp[i]=haha;
    }
    return temp;
}
void print(vector<string>s){
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;
    }
}
int match(vector<string>image1,vector<string>image2){
    //cout<<"matching starts!\n"<<endl;
    int n = image1.size(),m = image1[0].size();
    int n2 = image2.size(),m2 = image2[0].size();
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int k=0;k<n2&&i+k<n;k++){
                for(int l=0;l<m2&&j+l<m;l++){
                    if(image1[i+k][j+l]==image2[k][l]&&image2[k][l]=='#')
                        cnt++;
                }
            }
            res=max(res,cnt);
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
        res=max(res,match(image2,image1));
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            vector<string>tmp=image1;
            for(int k=0;k<=3;k++){
                tmp=rotate_clockNEW(tmp);
                for(int l=0;l<=i;l++)
                    tmp=flip_verticalNEW(tmp);
                for(int l=0;l<=j;l++)
                    tmp=flip_horizontal(tmp);
                res=max(res,match(tmp,image2));
                res=max(res,match(image2,tmp));
            }
        }
    }
    cout<<res<<endl;
}
int main() {
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}