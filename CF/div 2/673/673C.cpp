/*
*/
#include<bits/stdc++.h>
using namespace std;
#define    flash           ios_base::sync_with_stdio(false);cin.tie(0);
#define    ff              first
#define    ss              second
#define    pb              push_back
#define    m_p             make_pair
#define    ret             return 0
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
const int MAX=3e5+10,MOD=1e9+7;
vector<int>pos[MAX];
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[a[i]].pb(0);
    }
    for(int i=0;i<n;i++){
        pos[a[i]].pb(i+1);
    }
    for(int i=0;i<n;i++){
        pos[a[i]].pb(n+1);
    }
    vector<int>suff(n+1);

    vector<bool>taken(n+1);
    for(int i=0;i<n;i++){
            if(taken[a[i]])continue;
            taken[a[i]]=1;
            int df = 0;
            int mx_df = 0;
            for(int j=1;j<pos[a[i]].size();j++){
                df = pos[a[i]][j] - pos[a[i]][j-1];
                mx_df = max(mx_df, df);
            }
            suff[a[i]] = mx_df;
            //cout<<a[i]<<" "<<mx_df<<endl;
    }
    vector<pii>aw;

    for(int i=0;i<n+1;i++)taken[i]=0;
    for(int i=0;i<n;i++){
        if(taken[a[i]])continue;
        aw.pb({suff[a[i]],a[i]});
        taken[a[i]]=1;
    }
    sort(aw.begin(),aw.end());

    vector<int>res(n+1,1e9);

    for(int i=0;i<aw.size();i++){
            int idx = aw[i].first;
            res[idx] = min(res[idx],aw[i].second);
            //cout<<idx<<" "<<res[idx]<<endl;
    }
    int pr = -1;
    for(int i=1;i<=n;i++){
        if(res[i]==1e9)res[i]=pr;
        else pr = res[i];
    }
    pr = -1;
    for(int i=1;i<=n;i++){
        if(res[i]==-1)continue;
        if(pr == -1)pr = res[i];
        if(res[i]>pr)res[i]=pr;
        else pr = res[i];
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)pos[i].clear();
}
int main ()
{
    flash;
    int t;cin >> t;
    while(t--)solve();
    return 0;
}
/*
2
7 10
1 2 3 4 5 6 6
4 2
1 1 1 1
*/



