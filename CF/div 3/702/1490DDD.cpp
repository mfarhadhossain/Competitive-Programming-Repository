/*
    Author: thehalfblo0dprince
    From  : JU(46), IIT(08)
    Date  : 16.02.2021
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
const int MAX=105,MOD=1e9+7;
int n,a[MAX],pos[MAX],par[MAX],vis[MAX],taken[MAX];
vector<int>g[MAX];
void gen(int mx,int root,int mx_pos){
        if(vis[mx])return;

        //cout<<"mx = "<<mx<<" element pos = "<<mx_pos<<endl;
        vis[mx] = true;
        taken[mx]=true;

        int mx_l=-1,mx_r=-1;

        int st = mx_pos , en =mx_pos;

//        if(mx!=root && pos[par[mx]]<mx_pos){
//            st = pos[par[mx]]+1;
//            en = n;
//        }
//        if(mx!=root && pos[par[mx]]>mx_pos){
//            st = 0;
//            en = pos[par[mx]];
//        }
        for(int i=mx_pos-1;i>=0;i--){
            if(vis[a[i]]==true){
                break;
            }
            st=i;
        }
        for(int i=mx_pos+1;i<n;i++){
            if(vis[a[i]]==true){
                break;
            }
            en=i;
        }
        //cout<<"for "<<mx<<" range ["<<st<<","<<en<<"]"<<endl;
        int mx_l_pos=-1;
        int mx_r_pos=-1;
        for(int i=st;i<mx_pos;i++){
            if(taken[a[i]]==true)continue;

            if(mx_l<a[i]){
                mx_l = a[i];
                mx_l_pos=i;
            }
        }
        if(mx_l!=-1){
                taken[mx_l]=true;
                g[mx].push_back(mx_l);
                par[mx_l]=mx;

        }

        for(int i=mx_pos+1;i<=en;i++){
            if(taken[a[i]]==true)continue;

            if(mx_r<a[i]){
                mx_r = a[i];
                mx_r_pos=i;
            }
        }

        if(mx_r!=-1){
                taken[mx_r]=true;
                g[mx].push_back(mx_r);
                par[mx_r]=mx;
        }
        if(mx_l_pos!=-1)gen(mx_l,mx,mx_l_pos);
        if(mx_r_pos!=-1)gen(mx_r,mx,mx_r_pos);
}
int dres[MAX];
void dfs(int root,int par){
    dres[root]=dres[par]+1;
    for(int v:g[root]){
        if(v!=par)
        dfs(v,root);
    }
}
void solve(){
    cin>>n;
    int mx = 0,mx_pos=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]]=i;
        if(mx<a[i]){
            mx = a[i];
            mx_pos = i;
        }
    }
    gen(mx,mx,mx_pos);

    dres[mx]=-1;

    dfs(mx,mx);
    for(int i=0;i<n;i++)cout<<dres[a[i]]<<" ";
    cout<<endl;
//    vector<bool>vis(n+1),taken(n+1);
//    int root=-1;
//    while(true){
//        int bad=0;
//        for(int i=1;i<=n;i++){
//            if(vis[i]==false){
//                bad=1;
//                break;
//            }
//        }
//        if(bad==0)break;
//        int mx = -1,mx_pos=0;
//        for(int i=0;i<n;i++){
//            if(vis[a[i]]==true)continue;
//
//            if(mx<a[i] && taken[a[i]]==true){
//                mx = a[i];
//                mx_pos = i;
//            }
//        }
//        if(mx!=-1) {vis[mx] = true; taken[mx]=true;}
//        if(mx==-1)break;
//
//        if(root==-1){
//            root = mx;
//        }
//        int mx_l=-1,mx_r=-1;
//
//        int st = 0 , en =n;
//        if(mx!=root && pos[par[mx]]<mx_pos){
//            st = pos[par[mx]]+1;
//            en = n;
//        }
//        if(mx!=root && pos[par[mx]]>mx_pos){
//            st = 0;
//            en = pos[par[mx]];
//        }
//        for(int i=st;i<mx_pos;i++){
//            if(taken[a[i]]==true)continue;
//
//            if(mx_l<a[i]){
//                mx_l = a[i];
//            }
//        }
//        if(mx_l!=-1){taken[mx_l]=true;g[mx].push_back(mx_l);par[mx_l]=mx;}
//
//        for(int i=mx_pos+1;i<en;i++){
//            if(taken[a[i]]==true)continue;
//
//            if(mx_r<a[i]){
//                mx_r = a[i];
//            }
//        }
//
//        if(mx_r!=-1){taken[mx_r]=true;g[mx].push_back(mx_r);par[mx_r]=mx;}
//    }

//    for(int i=1;i<=n;i++){
//        cout<<i<<": ";
//        for(int y:g[i])cout<<y<<" ";
//        cout<<endl;
//    }

    for(int i=1;i<=n;i++){a[i]=0,g[i].clear();pos[i]=0;taken[i]=0;vis[i]=0;dres[i]=0;}
}
int main ()
{
    flash;
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}


