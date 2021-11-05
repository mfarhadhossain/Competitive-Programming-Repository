#include<bits/stdc++.h>
using namespace std;
int res[55];
int fun(int x){
    int cnt=0,sq = sqrt(x);
    for(int i=1;i<=sq;i++){
        if(x%i==0)cnt++;
    }
    return cnt;
}
int main (){
    cout<<"haha";
    for(int i=10000000;i<=100000000;i++){
            int k = fun(i);
            if(k==31||37==k||k==47){
                cout<<"for "<<k<<" = "<<i<<endl;

            }
            //cout<<i<<endl;
    }
    //for(int i=1;i<=50;i++)cout<<"res["<<i<<"] = "<<res[i]<<endl;
    return 0;
}
/*
res[1] = 1
res[2] = 4
res[3] = 12
res[4] = 24
res[5] = 36
res[6] = 60
res[7] = 192
res[8] = 120
res[9] = 180
res[10] = 240
res[11] = 576
res[12] = 360
res[13] = 1296
res[14] = 900
res[15] = 720
res[16] = 840
res[17] = 9216
res[18] = 1260
res[19] = 786432
res[20] = 1680
res[21] = 2880
res[22] = 15360
res[23] = 3600
res[24] = 2520
res[25] = 6480
res[26] = 61440
res[27] = 6300
res[28] = 6720
res[29] = 2359296
res[30] = 5040
res[31] = 0
res[32] = 7560
res[33] = 46080
res[34] = 983040
res[35] = 25920
res[36] = 10080
res[37] = 0
res[38] = 32400
res[39] = 184320
res[40] = 15120
res[41] = 44100
res[42] = 20160
res[43] = 5308416
res[44] = 107520
res[45] = 25200
res[46] = 2985984
res[47] = 0
res[48] = 27720
res[49] = 233280
res[50] = 45360
*/
