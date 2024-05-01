#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5+7, MOD = 1e9+7;
void solve()
{
    string s;
    cin>>s;
    string x="0";
    int n=s.size(),f=0,pos=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]>='5'){
            f=1;
            pos=i;
            break;
        }
        x.push_back(s[i]);
    }
    if(f==0){
        cout<<s<<endl;
    }
    else
    {
        int m = x.size();
        for(int j=m-1;j>=0;j--){
            if(x[j] <= '3'){

                if(x[j]=='0')x[j]='1';
                else if(x[j]=='1')x[j]='2';
                else if(x[j]=='2')x[j]='3';
                else if(x[j]=='3')x[j]='4';
                break;
            }
            x[j]='0';
        }
        if(x[0]=='0'){
            cout<<x.substr(1);
        }else{

            cout<<x;
        }
        n-=pos;
        while(n--)cout<<"0";
        cout<<endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout<<"case "<<tc<<": ";
        solve();
    }
    return 0;
}
