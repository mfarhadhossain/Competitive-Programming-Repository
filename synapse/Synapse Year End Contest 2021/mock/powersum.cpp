#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int  main ()
{
    int cnt=0;
    string ss;
    while(cin>>ss){
        cnt+=ss.size();
        if(ss=="end")break;
    }
    cout<<cnt<<endl;
	return 0;
}