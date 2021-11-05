#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree <
//                     T,
//                     null_type,
//                     less<T>,
//                     rb_tree_tag,
//                     tree_order_statistics_node_update >;
//ordered_set<int> S;
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
typedef    pair<int, int> pii;
typedef    pair<int, pii> ppi;
typedef    pair<pii, int> pip;
typedef    long long int ll;
typedef    unsigned long long int ull;
typedef    pair<ll, ll> pll;
typedef    vector<int> VI;
typedef    vector<pii> Vii;
typedef    vector<VI> VVI;// 2D
//typedef    priority_queue<int> PQ;// MaxHeap
typedef    priority_queue<int, VI, greater<int> > PQ; // MinHeap
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
const int MAX = 5e5 + 10, MOD = 1e9 + 7;
ll table[MAX][30];
int possible(int i, int j) {
    int gd = 0, bad = 0;
    vector<int>a, b;
    for (int k = 0; k < 26; k++) {
        if (table[i][k])a.push_back(table[i][k]);
        if (table[j][k])b.push_back(table[j][k]);
    }
    if (a.size() != b.size())
        return 0;
    int tot = a.size();
    for (int k = 0; k < a.size(); k++) {
        if (b[k] >= a[k] * 2) {
            gd++;
        }
        else {
            bad++;
        }
    }
    // if (bad > 1)return 1;
    // return 2;
    // cout << "i = " << i << " j =" << j << endl;
    //cout << gd << " " << bad << endl;
    if (tot - 1 == gd && bad == 1)
        return 2; // perfect
    if (gd > tot - 1)
        return 3; // extra

    return 1; // short
}
void solve() {
    string t; cin >> t;
    int n = t.size();
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[t[i] - 'a']++;
        table[i][t[i] - 'a'] = 1;
        for (int j = 0; j < 26; j++) {
            table[i][j] = table[i][j] + table[i - 1][j];
        }
    }
    string s = "";
    int res = 0, gd = 0;
    for (int i = n - 1; i >= 0; i--) {

        int l = i + 1, r = n - 1, bad = 0;

        while (l < r) {
            int md = (l + r) / 2;


            if (possible(i, md) == 0) {
                bad = 1;
                break;
            }
            if (possible(i, md) == 1) {
                l = md + 1;
            }
            else {
                res = i;
                r = md;
            }
        }
        if (bad == 0) {
            for (int k = max(0, l - 20); k <= min(n - 1, r + 20); k++) {
                if (possible(i, k) == 2) {
                    res = k;
                    gd = 1;
                    break;
                }
            }
            if (gd)break;
        }
        //cout << "i = " << bad << endl;
    }
    //cout << gd << endl;
    if (gd == 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i <= res; i++) {
        s.push_back(t[i]);
    }
    cout << s << endl;

    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= 26; k++)
            table[i][k] = 0;
    }
}
int main ()
{
    string s; cin >> s;
    if (s == "Hello,World!")cout << "AC";
    else cout << "WA";

    return 0;
}