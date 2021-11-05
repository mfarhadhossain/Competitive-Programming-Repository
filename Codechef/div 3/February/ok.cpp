/*
1 - 1
2 - 5
0 - 0
8 - 8
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5+7,MOD = 1e9+7;
int h,m;
bool good(string s){

    int hh = (s[0]-'0')*10 + (s[1]-'0');
    int mm = (s[3]-'0')*10 + (s[4]-'0');
    for(int i=0;i<s.size();i++){
        if(s[i]==':')continue;

        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='5'||s[i]=='8')continue;
        return 0;
    }
    return (hh<h && mm<m);
}
string dc(int x){
    if(x==0)return "0";
    if(x==1)return "1";
    if(x==2)return "2";
    if(x==3)return "3";
    if(x==4)return "4";
    if(x==5)return "5";
    if(x==6)return "6";
    if(x==7)return "7";
    if(x==8)return "8";
    if(x==9)return "9";
}
string make_time(int hh,int mm){

    int b = hh%10;
    hh/=10;
    int a = hh;

    int d = mm%10;
    mm/=10;
    int c = mm;

    string res = dc(a)+dc(b)+":"+dc(c)+dc(d);
    return res;
}
string inc(string s){
    int hh = (s[0]-'0')*10 + (s[1]-'0');
    int mm = (s[3]-'0')*10 + (s[4]-'0');

    mm++;
    if(mm==m){hh++;}
    hh=hh%h;
    mm=mm%m;
    return make_time(hh,mm);
}
string rev(string s){
    reverse(s.begin(),s.end());

    for(int i=0;i<s.size();i++){
        if(s[i]=='2')s[i]='5';
        else if(s[i]=='5')s[i]='2';
        else if(s[i]=='1')s[i]='1';
        else if(s[i]=='8')s[i]='8';
        else if(s[i]=='0')s[i]='0';
        else if(s[i]==':')s[i]=':';
        else        return "-1";
    }
    return s;
}
void solve(){
    cin>>h>>m;
    string s;
    cin>>s;
    while(true){
        string sr = rev(s);

        if(sr!="-1" && good(rev(s))){
            cout<<s<<endl;
            return;
        }
        s = inc(s);
    }
}
int main (){
    ll a = (ll)1LL*1e15;
    ll b = (ll)1LL*1e13;
    cout<<__gcd(a , b)%MOD<<endl;
    cout<<__gcd( b%MOD , a%MOD)<<endl;
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
////
//    int t;cin>>t;
//    while(t--)solve();
    return 0;
}



