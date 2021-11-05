#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e6+7;
bool isprime[MAX+100];
int Primes[MAX],id,res[MAX];// for <=10^6
void sieve()
{
    Primes[0]=2;
    id++;
    for(int i=4;i<=MAX+100;i+=2) isprime[i]=true;// is not a prime
    for(int i=3;i<=MAX+100;i+=2)
    {
        if(isprime[i]==false)
        {
            Primes[id++]=i;
            if(i+i<=MAX)
            for(int j=i+i;j<=100+MAX;j+=i)
                isprime[j]=true;
        }
    }
}
void precal(){
    for(int i=3;i<MAX;i++){
        if( isprime[i]==false && isprime[i+2]==false){
            res[i+2]++;
        }
    }
    for(int i=1;i<MAX;i++)res[i]+=res[i-1];
}
void solve(){
    int n;cin>>n;
    cout<<res[n]<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    precal();
    int t;cin>>t;
    while(t--)solve();
    return 0;
}



