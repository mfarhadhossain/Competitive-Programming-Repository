#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll r1,c1,r2,c2;

    cin>>r1>>c1;
    cin>>r2>>c2;

    if(r1==r2&&c1==c2)cout<<0<<endl;
    else if( (abs(r1-r2)+abs(r2-c2)<=3) || r1-c1==r2-c2 || r1+c1==r2+c2)cout<<1<<endl;
    else if( (r1+c1)%2 == (r2+c2)%2 )cout<< 2 <<endl;
    else{
            for(int i=-3;i<=3;i++){
                for(int j=-3;j<=3;j++){

                    if(abs(i)+abs(j) > 3)continue;


                    ll r3 = r1 + i,c3 = c1 + j;

                    if(abs(r3 - r2)+abs(c3-c2)<=3 || r3-c3==r2-c2 || r3+c3==r2+c2){
                            cout<< 2 <<endl;
                            return 0;

                    }
                }
            }
            cout<< 3 <<endl;
    }
    return 0;
}



