/*Farhad*/
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
/*inline int StringToInt(String a){int num;StringSeam aw(a);aw>>num;return num;}*/
/*inline ll StringToLL(String a){ll num;StringSeam aw(a);aw>>num;return num;}*/
//Math
/*inline int iPOW(int a,int e){int num=1;while(e){if(e%2){num=num * a;}e/=2;a=a * a;}return num;}*/
/*inline ll LPOW(ll a,ll e){ll num=1;while(e){if(e%2){num=num * a;}e/=2;a=a * a;}return num;}*/
/*inline ll BigMod(ll a,ll e,ll mod){ll num=1;while(e){if(e%2){a%=mod;num%=mod;num=num * a;num%=mod;}e/=2;a%=mod;a=a * a;a%=mod;}return num%mod;}*/
/*inline ll modInverse(ll A,ll P){return BigMod(A,P-2,P);}ll fac[MAX];
inline void factorial(int n,int mod){fac[0]=1;fac[1]=1;for(int i=2;i<=MAX;i++) fac[i]=( (fac[i-1]%mod)*i)%mod;}
inline int nCr(int n,int r,int mod) // ncr with mod{return ((fac[n] * modInverse(fac[r],mod)%mod)%mod * (modInverse(fac[n-r],mod)%mod) ) %mod;}*/
/*bool isprime[MAX+1000];int Primes[MAX],id;// for <=10^6
void sieve(){Primes[0]=2;id++;for(int i=4;i<=MAX+100;i+=2) isprime[i]=true;// is not a primefor(int i=3;i<=MAX+100;i+=2){if(isprime[i]==false){Primes[id++]=i;if(i+i<=MAX)for(int j=i+i;j<=100+MAX;j+=i)isprime[j]=true;}}}*/
//bigint
/*code from arpa
overloaded operators:
EQUAL::::::::::::: = (bigint), = (long long) , == (bigint) ,!=(bigint)
ADD::::::::::::::: + (bigint) , += (bigint)
SUB::::::::::::::: - (bigint) , -= (bigint),
MUL::::::::::::::: *=(int) , *(int),*(long long) , *(bigint) , *=(long long) ,*= (bigint)
DIV::::::::::::::: / (int) , / (bigint) , /= (int) ,/= (bigint),
MOD::::::::::::::: %(int), % (bigint),
COMPARE::::::::::: < (bigint) ,> (bigint) ,<= (bigint) ,>= (bigint) ,
ABS::::::::::::::: -() (bigint)
POW::::::::::::::: ^ (bigint);
functions: size() , returns size
to_string() , converts to string
sumof() , returns sum of digits
divmod() , dunno what it does
trim() , trims trailing zeroes
isZero() , zero or not
abs() , absolute value
longValue() , to long
gcd(a,b) , gcd
lcm(a,b) , lcm
convert_base() , converts base
karatsubaMultiply(const vll &a, const vll &b) , dunno what it does
*/
#include<bits/stdc++.h>
using namespace std;
const int base = 1000000000, base_digits = 9;
struct bigint {
    vector<int> a; int sign;
    int size() {if (a.empty())return 0; int ans = (a.size() - 1) * base_digits; int ca = a.back(); while (ca)ans++, ca /= 10; return ans;}
    bigint operator ^(const bigint &v) {bigint ans = 1, a = *this, b = v; while (!b.isZero()) {if (b % 2)ans *= a; a *= a, b /= 2;} return ans;}
    string to_string() {stringstream ss; ss << *this; string s; ss >> s; return s;}
    int sumof() {string s = to_string(); int ans = 0; for (auto c : s)  ans += c - '0'; return ans;}
    bigint() : sign(1) {}
    bigint(long long v) {*this = v;}
    bigint(const string &s) {read(s);}
    void operator=(const bigint &v) {sign = v.sign; a = v.a;}
    void operator=(long long v) {sign = 1; a.clear(); if (v < 0)sign = -1, v = -v; for (; v > 0; v = v / base)a.push_back(v % base);}
    bigint operator+(const bigint &v) const {if (sign == v.sign) {bigint res = v; for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {if (i == (int) res.a.size())res.a.push_back(0); res.a[i] += carry + (i < (int) a.size() ? a[i] : 0); carry = res.a[i] >= base; if (carry)res.a[i] -= base;} return res;} return *this - (-v);}
    bigint operator-(const bigint &v) const {if (sign == v.sign) {if (abs() >= v.abs()) {bigint res = *this; for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0); carry = res.a[i] < 0; if (carry)res.a[i] += base;} res.trim(); return res;} return -(v - *this);} return *this + (-v);}
    void operator*=(int v) {if (v < 0)sign = -sign, v = -v; for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {if (i == (int) a.size())a.push_back(0); long long cur = a[i] * (long long) v + carry; carry = (int) (cur / base); a[i] = (int) (cur % base);/*//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));*/} trim();}
    bigint operator*(int v) const {bigint res = *this; res *= v; return res;}
    void operator*=(long long v) {if (v < 0)sign = -sign, v = -v; for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {if (i == (int) a.size())a.push_back(0); long long cur = a[i] * (long long) v + carry; carry = (int) (cur / base); a[i] = (int) (cur % base);/*//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));*/} trim();}
    bigint operator*(long long v) const {bigint res = *this; res *= v; return res;}
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {int norm = base / (b1.a.back() + 1); bigint a = a1.abs() * norm; bigint b = b1.abs() * norm; bigint q, r; q.a.resize(a.a.size()); for (int i = a.a.size() - 1; i >= 0; i--) {r *= base; r += a.a[i]; int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()]; int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1]; int d = ((long long) base * s1 + s2) / b.a.back(); r -= b * d; while (r < 0)r += b, --d; q.a[i] = d;} q.sign = a1.sign * b1.sign; r.sign = a1.sign; q.trim(); r.trim(); return make_pair(q, r / norm);}
    bigint operator/(const bigint &v) const {return divmod(*this, v).first;}
    bigint operator%(const bigint &v) const {return divmod(*this, v).second;}
    void operator/=(int v) {if (v < 0)sign = -sign, v = -v; for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {long long cur = a[i] + rem * (long long) base; a[i] = (int) (cur / v); rem = (int) (cur % v);} trim();}
    bigint operator/(int v) const {bigint res = *this; res /= v; return res;}
    int operator%(int v) const {if (v < 0)v = -v; int m = 0; for (int i = a.size() - 1; i >= 0; --i)m = (a[i] + m * (long long) base) % v; return m * sign;}
    void operator+=(const bigint &v) {*this = *this + v;}
    void operator-=(const bigint &v) {*this = *this - v;}
    void operator*=(const bigint &v) {*this = *this * v;}
    void operator/=(const bigint &v) {*this = *this / v;}
    bool operator<(const bigint &v) const {if (sign != v.sign)return sign < v.sign; if (a.size() != v.a.size())return a.size() * sign < v.a.size() * v.sign; for (int i = a.size() - 1; i >= 0; i--)if (a[i] != v.a[i])return a[i] * sign < v.a[i] * sign; return false;}
    bool operator>(const bigint &v) const {return v < *this;}
    bool operator<=(const bigint &v) const {return !(v < *this);}
    bool operator>=(const bigint &v) const {return !(*this < v);}
    bool operator==(const bigint &v) const {return !(*this < v) && !(v < *this);}
    bool operator!=(const bigint &v) const {return *this < v || v < *this;}
    void trim() {while (!a.empty() && !a.back())a.pop_back(); if (a.empty())sign = 1;}
    bool isZero() const {return a.empty() || (a.size() == 1 && !a[0]);}
    bigint operator-() const {bigint res = *this; res.sign = -sign; return res;}
    bigint abs() const {bigint res = *this; res.sign *= res.sign; return res;}
    long long longValue() const {long long res = 0; for (int i = a.size() - 1; i >= 0; i--)res = res * base + a[i]; return res * sign;}
    friend bigint gcd(const bigint &a, const bigint &b) {return b.isZero() ? a : gcd(b, a % b);}
    friend bigint lcm(const bigint &a, const bigint &b) {return a / gcd(a, b) * b;}
    void read(const string &s) {sign = 1; a.clear(); int pos = 0; while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {if (s[pos] == '-')sign = -sign; ++pos;} for (int i = s.size() - 1; i >= pos; i -= base_digits) {int x = 0; for (int j = max(pos, i - base_digits + 1); j <= i; j++)x = x * 10 + s[j] - '0'; a.push_back(x);} trim();}
    friend istream& operator>>(istream &stream, bigint &v) {string s; stream >> s; v.read(s); return stream;}
    friend ostream& operator<<(ostream &stream, const bigint &v) {if (v.sign == -1)stream << '-'; stream << (v.a.empty() ? 0 : v.a.back()); for (int i = (int) v.a.size() - 2; i >= 0; --i)stream << setw(base_digits) << setfill('0') << v.a[i]; return stream;}
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {vector<long long> p(max(old_digits, new_digits) + 1); p[0] = 1; for (int i = 1; i < (int) p.size(); i++)p[i] = p[i - 1] * 10; vector<int> res; long long cur = 0; int cur_digits = 0; for (int i = 0; i < (int) a.size(); i++) {cur += a[i] * p[cur_digits]; cur_digits += old_digits; while (cur_digits >= new_digits) {res.push_back(int(cur % p[new_digits])); cur /= p[new_digits]; cur_digits -= new_digits;}} res.push_back((int) cur); while (!res.empty() && !res.back())res.pop_back(); return res;}
    typedef vector<long long> vll;
    static vll karatsubaMultiply(const vll &a, const vll &b) {int n = a.size(); vll res(n + n); if (n <= 32) {for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)res[i + j] += a[i] * b[j]; return res;} int k = n >> 1; vll a1(a.begin(), a.begin() + k); vll a2(a.begin() + k, a.end()); vll b1(b.begin(), b.begin() + k); vll b2(b.begin() + k, b.end()); vll a1b1 = karatsubaMultiply(a1, b1); vll a2b2 = karatsubaMultiply(a2, b2); for (int i = 0; i < k; i++)a2[i] += a1[i]; for (int i = 0; i < k; i++)b2[i] += b1[i]; vll r = karatsubaMultiply(a2, b2); for (int i = 0; i < (int) a1b1.size(); i++)r[i] -= a1b1[i]; for (int i = 0; i < (int) a2b2.size(); i++)r[i] -= a2b2[i]; for (int i = 0; i < (int) r.size(); i++)res[i + k] += r[i]; for (int i = 0; i < (int) a1b1.size(); i++)res[i] += a1b1[i]; for (int i = 0; i < (int) a2b2.size(); i++)res[i + n] += a2b2[i]; return res;}
    bigint operator*(const bigint &v) const {vector<int> a6 = convert_base(this->a, base_digits, 6); vector<int> b6 = convert_base(v.a, base_digits, 6); vll a(a6.begin(), a6.end()); vll b(b6.begin(), b6.end()); while (a.size() < b.size())a.push_back(0); while (b.size() < a.size())b.push_back(0); while (a.size() & (a.size() - 1))a.push_back(0), b.push_back(0); vll c = karatsubaMultiply(a, b); bigint res; res.sign = sign * v.sign; for (int i = 0, carry = 0; i < (int) c.size(); i++) {long long cur = c[i] + carry; res.a.push_back((int) (cur % 1000000)); carry = (int) (cur / 1000000);} res.a = convert_base(res.a, 6, base_digits); res.trim(); return res;}
};
//int Dx[] ={-1,0, 0,1};int Dy[] ={ 0,1,-1,0};int Dx8[]={-1,-1,-1,0,1,1, 1, 0};int Dy8[]={-1, 0, 1,1,1,0,-1,-1};int Kx[] ={2,1,-1,-2,-2,-1, 1, 2};int Ky[] ={1,2, 2, 1,-1,-2,-2,-1};
//code starts from here
//const int MAX=1e5+10,MOD=1e9+7;
int main ()
{
    //flash;
    return 0;
}