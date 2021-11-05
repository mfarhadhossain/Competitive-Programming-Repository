/*
*/
#include<bits/stdc++.h>
using namespace std;
#define    flash           ios_base::sync_with_stdio(false);cin.tie(0);
#define    ff              first
#define    ss              second
#define    pb              push_back
#define    m_p             make_pair
//#define    ret             return 0
#define    MAX(a,b)        max({a,b})
#define    MAX(a,b,c)      max({a,b,c})
#define    MAX(a,b,c,d)    max({a,b,c,d})
#define    MIN(a,b)        min({a,b})
#define    MIN(a,b,c)      min({a,b,c})
#define    MIN(a,b,c,d)    min({a,b,c,d})
#define    GCD(a,b)        __gcd(a,b)
#define    LCM(a,b)        (a*b)/GCD(a,b)
#define    MEM(a,b)        memset(a,b,sizeof a)
#define    SC(a)           scanf("%d",&a)
#define    SC2(a,b)        scanf("%d %d",&a,&b)
#define    SC3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define    SC4(a,b,c,d)    scanf("%d %d %d %d",&a,&b,&c,&d)
#define    PCs(a)          printf("Case %d: ",a)
#define    WRITE(a)        freopen(a,"w",stdout)
#define    READ(a)         freopen(a,"r",stdin)
#define    LB(a,x)         (lower_bound(a.begin(),a.end(),x) - a.begin())
#define    UB(a,x)         (upper_bound(a.begin(),a.end(),x) - a.begin())
#define    PI              2.0*acos(0.0)
#define    MOD1            1000000007 // prime
#define    MOD2            1000000009 // prime
#define    MOD3            1000000021 // prime
#define    Base1           10000019
#define    Base2           10000079
#define    Base3           10000103
#define    endl             '\n'
//#define    MAX             1000007
typedef    pair<int,int> pii;
typedef    pair<int,pii> ppi;
typedef    pair<pii,int> pip;
typedef    long long int ll;
typedef    unsigned long long int ull;
typedef    pair<ll,ll> pll;
typedef    vector<int> VI;
typedef    vector<pii> Vii;
typedef    vector<VI> VVI;// 2D
//typedef    priority_queue<int> PQ;// MaxHeap
typedef    priority_queue<int,VI,greater<int> > PQ;// MinHeap
/*
inline int StringToInt(String a)
{
    int num;
    StringSeam aw(a);
    aw>>num;
    return num;
}*/
/*
inline ll StringToLL(String a)
{
    ll num;
    StringSeam aw(a);
    aw>>num;
    return num;
}*/
/*
inline int iPOW(int a,int e)
{
    int num=1;
    while(e)
    {
        if(e%2)
        {
            num=num * a;
        }
        e/=2;
        a=a * a;
    }
    return num;
}
inline ll LPOW(ll a,ll e)
{
    ll num=1;
    while(e)
    {
        if(e%2)
        {
            num=num * a;
        }
        e/=2;
        a=a * a;
    }
    return num;
}*/
/*
inline ll BigMod(ll a,ll e,ll mod)
{
    ll num=1;
    while(e)
    {
        if(e%2)
        {
            a%=mod;
            num%=mod;
            num=num * a;
            num%=mod;
        }
        e/=2;
        a%=mod;
        a=a * a;
        a%=mod;
    }
    return num%mod;
}*/
/*inline ll modInverse(ll A,ll P)
{
    return BigMod(A,P-2,P);
}
ll fac[MAX];
inline void factorial(int n,int mod)
{
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=MAX;i++) fac[i]=( (fac[i-1]%mod)*i)%mod;
}
inline int nCr(int n,int r,int mod) // ncr with mod
{
    return ((fac[n] * modInverse(fac[r],mod)%mod)%mod * (modInverse(fac[n-r],mod)%mod) ) %mod;
}
*/
/*
bool isprime[MAX+1000];
int Primes[MAX],id;// for <=10^6
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
}*/
//int Dx[] ={-1,0, 0,1};
//int Dy[] ={ 0,1,-1,0};
//int Dx8[]={-1,-1,-1,0,1,1, 1, 0};
//int Dy8[]={-1, 0, 1,1,1,0,-1,-1};
//int Kx[] ={2,1,-1,-2,-2,-1, 1, 2};
//int Ky[] ={1,2, 2, 1,-1,-2,-2,-1};

// code starts from here
const int MAX=1e5+10,MOD=1e9+7;
int n;
int fun(int ra1,int rb1,int pa1,int pb1,int sa1,int sb1){

    int ra=ra1,sa=sa1,pa=pa1;
    int rb=rb1,sb=sb1,pb=pb1;

    int tot_lose=0,tot_draw=0;
//draw
    int d = min(rb,sa);
    tot_lose+=d;
    rb-=d;
    sa-=d;
    d = min(ra,rb);
    tot_draw+=d;
    ra-=d;
    rb-=d;

    d = min(sb,pa);
    tot_lose+=d;
    sb-=d;
    pa-=d;
    d = min(pa,pb);
    tot_draw+=d;
    pa-=d;
    pb-=d;

    d = min(pb,ra);
    tot_lose+=d;
    pb-=d;
    ra-=d;
    d = min(sa,sb);
    tot_draw+=d;
    sa-=d;
    sb-=d;
    int res = (n - (tot_draw + tot_lose));
    ra=ra1,sa=sa1,pa=pa1;
    rb=rb1,sb=sb1,pb=pb1;

    tot_lose=0,tot_draw=0;
//draw
    d = min(rb,sa);
    tot_lose+=d;
    rb-=d;
    sa-=d;
    d = min(ra,rb);
    tot_draw+=d;
    ra-=d;
    rb-=d;

    d = min(sb,pa);
    tot_lose+=d;
    sb-=d;
    pa-=d;
    d = min(pa,pb);
    tot_draw+=d;
    pa-=d;
    pb-=d;

    d = min(pb,ra);
    tot_lose+=d;
    pb-=d;
    ra-=d;
    d = min(sa,sb);
    tot_draw+=d;
    sa-=d;
    sb-=d;
    res = min(res,(n - (tot_draw + tot_lose)));
    return res;
}
void solve(){
    cin>>n;
    int ra,sa,pa;
    int rb,sb,pb;
    cin >> ra >> sa >> pa;
    cin >> rb >> sb >> pb;

    int tot_win=0;
    int d = min(ra,sb);
    tot_win+=d;
    d = min(sa,pb);
    tot_win+=d;
    d = min(pa,rb);
    tot_win+=d;

    int tot_lose=0,tot_draw=0;
//draw
    d = min(rb,sa);
    tot_lose+=d;
    rb-=d;
    sa-=d;
d = min(sb,pa);
    tot_lose+=d;
    sb-=d;
    pa-=d;
    d = min(pa,pb);
d = min(pb,ra);
    tot_lose+=d;
    pb-=d;
    ra-=d;

    tot_draw+=d;
    pa-=d;
    pb-=d;

    d = min(ra,rb);
    tot_draw+=d;
    ra-=d;
    rb-=d;
    d = min(sa,sb);
    tot_draw+=d;
    sa-=d;
    sb-=d;

    // bob win





    //cout<<ra<<" "<<sa<<" "<<pa<<endl;
    //cout<<rb<<" "<<sb<<" "<<pb<<endl;
    cout<<min(fun(ra,rb,pa,pb,sa,sb) ,n-(tot_draw+tot_lose))<<" "<<tot_win<<endl;
}
int main ()
{
    //flash;
    int t=10;//cin >> t;
    while(t--)solve();
    return 0;
}
/*

*/






