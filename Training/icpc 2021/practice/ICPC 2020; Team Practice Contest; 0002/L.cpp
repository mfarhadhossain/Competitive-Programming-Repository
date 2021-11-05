#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e7+7;
bool isprime[MAX];
int Primes[MAX],id;// for <=10^6
void sieve()
{
    Primes[0]=2;
    id++;
    for(int i=4;i<MAX;i+=2) isprime[i]=true;// is not a prime
    for(int i=3;i<MAX;i+=2)
    {
        if(isprime[i]==false)
        {
            Primes[id++]=i;
            if(i+i<MAX)
            for(int j=i+i;j<MAX;j+=i)
                isprime[j]=true;
        }
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();

    int n;cin>>n;

    while(n--){
        int a,b;cin>>a>>b;
        int res=0;
        unordered_map<int,int>cnt;

        if(a==1)res=0;
        else if(isprime[a]==false){res=1;cnt[a]=1;}
        else{
            for(int i=0;i<id&&Primes[i]<=a;i++){
                    if(a%Primes[i]==0){
                        while(a%Primes[i]==0){
                            a/=Primes[i];
                        }
                        if(cnt[Primes[i]]==0){
                            res++;
                            cnt[Primes[i]]=1;
                        }
                    }
            }
        }
        if(b==1)res=res;
        else if(isprime[b]==false){ if(cnt[b]==0)res++;}
        else{
            for(int i=0;i<id&&Primes[i]<=b;i++){
                    if(b%Primes[i]==0){
                        while(b%Primes[i]==0){
                            b/=Primes[i];
                        }
                        if(cnt[Primes[i]]==0){
                            res++;
                            cnt[Primes[i]]=1;
                        }
                    }
            }
        }

        cout<<res<<endl;

    }
    return 0;
}



