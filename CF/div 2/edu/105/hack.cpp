#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
int main (){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    freopen("out.txt","w",stdout);
    int tc=1000;
    cout<<tc<<endl;
    for(int i=2;i<=5&&tc>0;i++){


            for(int j=0;j<=i;j++){
                for(int k=0;k<=i;k++){
                    for(int l=0;l<=i;l++){
                        for(int m=0;m<=i;m++){
                            cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<endl;

                            tc--;
                            if(!tc)return 0;
                        }
                    }
                }
            }
    }
    return 0;
}



