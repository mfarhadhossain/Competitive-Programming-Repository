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
const int MAX=1e5+10,MOD=1e9+7;
int a[MAX],n;
int Lmin[MAX],Lmin2[MAX],Lmax[MAX],Lmax2[MAX];
int Rmin[MAX],Rmin2[MAX],Rmax[MAX],Rmax2[MAX];
ll fun(int a,int b,int c){
    ll a_ = a;
    ll b_ = b;
    ll c_ = c;
    return a_*b_*c_;
}
void solve(){
    cin >> n;
    ll aw=1;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            aw*=(ll)(a[i]);
    }
    if(n==5){
        cout<<aw<<endl;
        return;
    }
//    Lmin[0] = 1e9;
//    Lmin2[0] = 1e9;
//
//    Lmax[0] = -1e9;
//    Lmax2[0] = -1e9;

    for(int i=1;i<=n;i++){
            if(i==1){
                Lmin[i]=a[i];
                Lmax[i]=a[i];
                continue;
            }
            Lmin[i] = min(Lmin[i-1],a[i]);
            Lmax[i] = max(Lmax[i-1],a[i]);
    }
    for(int i=1;i<=n;i++){

            if(i==1){
                Lmin2[i]=a[i];
                Lmax2[i]=a[i];
                continue;
            }
            if(i==2){
                Lmin2[i]=a[i]*a[i-1];
                Lmax2[i]=a[i]*a[i-1];
                continue;
            }
//            cout<<i<<" te asi ";
//            cout<<" bame single prefix min "<<Lmin[i-1]<<endl;
//            cout<<" bame double prefix min "<<Lmin2[i-1]<<endl;
//            cout<<" potential ans "<<Lmax[i-1]*a[i]<<endl;
            Lmin2[i] = min(Lmin2[i-1],Lmax[i-1]*a[i]);
            Lmin2[i] = min(Lmin2[i],min(Lmin2[i-1],Lmin[i-1]*a[i]));

//            cout<<" potential ans "<<Lmin[i-1]*a[i]<<endl;
//            cout<<" calc ans "<<Lmin2[i]<<endl;
//            cout<<" bame single prefix max "<<Lmax[i-1]<<endl;
//            cout<<" bame double prefix max "<<Lmax2[i-1]<<endl;

            Lmax2[i] = max(Lmax2[i-1],Lmax[i-1]*a[i]);
            Lmax2[i] = max(Lmax2[i],max(Lmax2[i-1],Lmin[i-1]*a[i]));
//            cout<<" potential ans "<<Lmin[i-1]*a[i]<<endl;
//            cout<<" potential ans "<<Lmax[i-1]*a[i]<<endl;
//            cout<<" calc ans "<<Lmax2[i]<<endl;


    }
//    Rmin[n+1] = 1e9;
//    Rmin2[n+1] = 1e9;
//    Rmax[n+1] = -1e9;
//    Rmax2[n+1] = -1e9;
    for(int i=n;i>=1;i--){

            if(i==n){
                Rmin[i]=a[i];
                Rmax[i]=a[i];
                continue;
            }
            Rmin[i] = min(Rmin[i+1],a[i]);
            Rmax[i] = max(Rmax[i+1],a[i]);
    }
    for(int i=n;i>=1;i--){
            if(i==n){
                Rmin2[i]=a[i];
                Rmax2[i]=a[i];
                continue;
            }
            if(i==n-1){
                Rmin2[i]=a[i]*a[i+1];
                Rmax2[i]=a[i]*a[i+1];
                continue;
            }
            Rmin2[i] = min(Rmin2[i+1],Rmin[i+1]*a[i]);

            Rmin2[i] = min(Rmin2[i],min(Rmin2[i+1],Rmax[i+1]*a[i]));

            Rmax2[i] = max(Rmax2[i+1],Rmax[i+1]*a[i]);
            Rmax2[i] = max(Rmax2[i],max(Rmax2[i+1],Rmin[i+1]*a[i]));
    }
//    for(int i=1;i<=n;i++){
//        cout<<"i = "<<i;
//        cout<<" prefix single min "<<Lmin[i]<<endl;
//        cout<<"prefix double min "<<Lmin2[i]<<endl;
//    }
//    for(int i=1;i<=n;i++){
//        cout<<"i = "<<i;
//        cout<<" prefix single max "<<Lmax[i]<<endl;
//        cout<<"prefix double max "<<Lmax2[i]<<endl;
//    }
//    for(int i=1;i<=n;i++){
//        cout<<"i = "<<i;
//        cout<<" suffix single min "<<Rmin[i]<<endl;
//        cout<<"suffix double min "<<Rmin2[i]<<endl;
//    }
//    for(int i=1;i<=n;i++){
//        cout<<"i = "<<i;
//        cout<<" suffix single max "<<Rmax[i]<<endl;
//        cout<<"suffix double max "<<Rmax2[i]<<endl;
//    }
    ll res = -1e18;

    for(int i=3;i<=n-2;i++){
            ll ret1 = fun(Lmin2[i-1],Rmin2[i+1],a[i]);
//            cout<<"bame double min "<<Lmin2[i-1]<<endl;
//            cout<<"dane double min "<<Rmin2[i+1]<<endl;
//            cout<<"bame double max "<<Lmax2[i-1]<<endl;
//            cout<<"dane double max "<<Rmax2[i+1]<<endl;
            ll ret2 = fun(Lmax2[i-1],Rmax2[i+1],a[i]);

            ll ret3 = fun(Lmin2[i-1],Rmax2[i+1],a[i]);
            ll ret4 = fun(Lmax2[i-1],Rmin2[i+1],a[i]);
            res = max(res , ret1);
            res = max(res , ret2);
            res = max(res , ret3);
            res = max(res , ret4);
    }
    cout<<res<<endl;
}
int main ()
{
    //flash;
    flash;
    int t;cin >> t;
    while(t--)solve();
    return 0;
}
/*
2
6
0 1 2 3 4 5
6
1 2 3 4 5 0
*/
