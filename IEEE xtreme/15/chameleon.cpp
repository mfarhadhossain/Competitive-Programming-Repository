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
const int MAX=1e4+10,MOD=1e9+7;
int n,m,k;

vector< pair<int, pair<int,char>> >g[MAX];
int shortest_path_without_change(int s,int t){
    vector<int>dist(n+5,1e9);
    vector<bool>vs(n+5,0);
    dist[s]=0;
    vs[s]=0;


    priority_queue< pair<int, pair<int,char>> ,vector<pair<int, pair<int,char>>>,greater<pair<int, pair<int,char>>> > PQ;

    PQ.push(m_p(0,m_p(s,'a')));

    while(!PQ.empty())
    {
        auto u = PQ.top();
        PQ.pop();
        if(vs[u.ss.ff] or u.ss.ss!='a') continue;
        
        vs[u.ss.ff]=1;

        int sz = g[u.ss.ff].size();
        for(int i=0;i<sz;i++)
        {
            auto A=g[u.ss.ff][i];
            int v=A.ff;
            if(A.ss.ss!='a')continue;

            if(dist[v]>dist[u.ss.ff]+A.ss.ff && vs[v]==0)
            {
                dist[v] = dist[u.ss.ff]+A.ss.ff;
                PQ.push(m_p(dist[v],m_p(v,A.ss.ss)));
            }
        }
        //if(dist[t]!=INT_MAX)
           // break;
    }
    return dist[t];
}
int shortest_path_with_change(int s,int t){
    vector<int>dist(n+5,1e9);
    vector<bool>vs(n+5,0);
    dist[s]=0;
    vs[s]=0;


    priority_queue< pair<int, pair<int,char>> ,vector<pair<int, pair<int,char>>>,greater<pair<int, pair<int,char>>> > PQ;

    PQ.push(m_p(0,m_p(s,'a')));

    while(!PQ.empty())
    {
        auto u = PQ.top();
        PQ.pop();
        if(vs[u.ss.ff]) continue;
        
        vs[u.ss.ff]=1;

        int sz = g[u.ss.ff].size();
        for(int i=0;i<sz;i++)
        {
            auto A=g[u.ss.ff][i];
            int v=A.ff;
            int c=0;
            if(A.ss.ss!=u.ss.ss){
                c=1;
            }

            if(dist[v]>dist[u.ss.ff]+A.ss.ff && vs[v]==0)
            {
                dist[v] = dist[u.ss.ff]+A.ss.ff+c;
                PQ.push(m_p(dist[v],m_p(v,A.ss.ss)));
            }
        }
        //if(dist[t]!=INT_MAX)
           // break;
    }
    return dist[t];
}
int shortest_path_with_C(int s,int t,int c){
    vector<int>dist(n+5,1e9);
    vector<bool>vs(n+5,0);
    dist[s]=0;
    vs[s]=0;


    priority_queue< pair<int, pair<int,char>> ,vector<pair<int, pair<int,char>>>,greater<pair<int, pair<int,char>>> > PQ;

    PQ.push(m_p(0,m_p(s,'a')));

    while(!PQ.empty())
    {
        auto u = PQ.top();
        PQ.pop();
        if(vs[u.ss.ff]) continue;
        
        vs[u.ss.ff]=1;

        int sz = g[u.ss.ff].size();
        for(int i=0;i<sz;i++)
        {
            auto A=g[u.ss.ff][i];
            int v=A.ff,c_=0;
            if(A.ss.ss!=u.ss.ss){
                c_=c;
            }

            if(dist[v]>dist[u.ss.ff]+A.ss.ff && vs[v]==0)
            {
                dist[v] = dist[u.ss.ff]+A.ss.ff+c_;
                PQ.push(m_p(dist[v],m_p(v,A.ss.ss)));
            }
        }
        //if(dist[t]!=INT_MAX)
           // break;
    }
    return dist[t];
}
void solve(){
    cin>>n>>m>>k;

    for(int i=0;i<m;i++){
        int u,v,w;
        char col;
        cin>>u>>v>>w>>col;
        g[u].push_back({v,{w,col}});
        g[v].push_back({u,{w,col}});
    }
    int cost1 = shortest_path_without_change(1,n);
    //cout<<cost1<<endl;
    if(cost1!=1e9 && cost1<=k){
        cout<<"relaxing"<<endl;
        return;
    }
    int cost2 = shortest_path_with_change(1,n);
    //cout<<cost2<<endl;
    if(cost2>k){
        cout<<"impossible\n";
        return;
    }
    int res=0;
    for(int kk=1;kk<=50;kk++){
        if(shortest_path_with_C(1,n,kk)<=k){
            res=max(res,kk);
        }
    }
    cout<<res<<endl;
    for(int i=0;i<n;i++)
        g[i].clear();
}
int main ()
{
    //flash;
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}