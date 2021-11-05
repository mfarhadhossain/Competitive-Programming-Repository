#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
int n,k,mx=0;
vector<int>res;
bool fun(vector<int>s){
    int sz= s.size();

    for(int i=0;i<(1<<sz);i++){
        int sum=0;
        for(int j=0;j<sz;j++){
            if( (1<<j) & i){
                sum+=s[j];
            }
        }
        if(sum==k)return 0;
    }
    return 1;
}
void solve(vector<int>s,int x){
    if(x>n){
        int sum=0;
        for(int xx:s){sum+=xx;}
        if(fun(s)){
            if(s.size()>mx){
                mx = s.size();
                res = s;
            }
        }

        return;
    }

    s.push_back(x);
    solve(s,x+1);
    s.pop_back();
    solve(s,x+1);
}
int main (){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

cin>>n>>k;
mx = 0;
res.clear();
solve({},1);
cout<<res.size()<<endl;
{for(int x:res)cout<<x<<" ";
cout<<endl;}
main();
    return 0;
}



