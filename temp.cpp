// euler totient
const int MAX = 10000; int phi[MAX], mark[MAX];
void func() {for (int i = 1; i < MAX; i++)phi[i] = i; phi[1] = 1; /* should be defined*/mark[1] = 1; for (int i = 2; i < MAX; i++) {if (!mark[i]) {for (int j = i; j < MAX; j += i) {mark[j] = 1; phi[j] = phi[j] / i * 1LL * (i - 1);}}}}
//fraction
class fraction {
public: typedef long long int ll;
    ll nom, denom;
    fraction() {nom = denom = 0;} fraction(ll x) {nom = x , denom = 1;}
    fraction(ll x, ll y) {nom = x , denom = y;}
    void norm() {ll g = __gcd(nom, denom); nom /= g; denom /= g; if (nom == 0)denom = 1; if (denom < 0)denom *= -1, nom *= -1;}
    fraction operator + (fraction obj) {ll lc = lcm(obj.denom, denom); fraction r ( nom * (lc / denom) + obj.nom * (lc / obj.denom), lc ); r.norm(); return r;}
    fraction operator - (fraction obj) {ll lc = lcm(obj.denom, denom); fraction r ( nom * (lc / denom) - obj.nom * (lc / obj.denom), lc ); r.norm(); return r;}
    fraction operator * (ll x) {return {nom * x , denom};}
    void print() {cerr << nom << "/" << denom << endl;}
};
// factorial-factorising
vector<pii> factfactorise(int n)
{
    vector<pii> F;
    for (int i = 0; i < id && primes[i] <= n; i++) {
        ll curr = primes[i];
        ll num = n ;
        ll cnt = 0 ;
        while ( num / curr) {
            cnt += num / curr;
            curr *= primes[i];
        }
        if (cnt)
            F.push_back({primes[i] , cnt});

    }
    return F;
}