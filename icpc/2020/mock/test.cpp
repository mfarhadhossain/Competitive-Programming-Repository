/*
                                Bismillahi-r-Rahmani-r-Rahim
                                        RhIeyAaD
                                    IIT-7th Batch,JU
*/
#include<bits/stdc++.h>
using namespace std;

// #define debug(args...){ string _s = #args;replace(_s.begin(),_s.end(),',', ' ');stringstream _ss(_s);istream_iterator<string>_it(_ss);err(_it, args);} cout<<endl;
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}

#define ll              long long int
#define MAX             2134567891
#define pf(a)           printf("%lld", a)
#define sf(a)           scanf("%lld", &a)
#define sf2(a,b)        scanf("%lld %lld", &a, &b)
#define fr(i,n)         for(i=0;i<n;i++)
#define rep(i,n)        for(i=1;i<=n;i++)
#define rev(i,a,n)      for(i=n;i>=a;i--)
#define FOR(i,a,n)      for(i=a;i<=n;i++)
#define ALL(n)          n.begin(),n.end()
#define mem(x,n)        memset(x,n,sizeof(x))
#define TC(t)           printf("Case %lld: ",t)
#define ans(t,c)        printf("Case %lld: %lld\n",t,c)
#define SETP(n)         cout<<setprecision(n)<<fixed
#define READ            freopen("F:\\Project\\Test_Case.txt","r",stdin)
#define WRITE           freopen("F:\\Project\\Output_Test.txt","w",stdout)
#define IO              ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define PAIR            pair<ll,ll>
#define MP              make_pair
#define pb              push_back
#define eb              emplace_back
#define ff              first
#define ss              second
#define NL              printf("\n");
#define bug(a)          cout<<#a<<" "<<a<<" ";
#define hlw             printf("hlw\n");
#define NN              111
#define MOD             1000000007///10^9
#define N               1000007 ///10^6->6 zero after 1 **



ll pr1[100], y[N], z[N], n;
string s, S;
vector<ll>v, pr{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
//bitset<N>B;
//map <ll,ll> mp;
ll fun(ll l, ll st, ll en)
{
    ll a = 0, b, c = 0, cnt, i, j, k, n, ans = 0, p, q, r;
    cnt = (1 << l);

    rep(i, cnt - 1)
    {
        a = 1;
        fr(j, l)
        {
            //debug(i,j)
            if (i & 1 << j)
            {
                a *= v[j];
            }
        }
        p = en / a;
        q = st / a;
        r = p - q;

        b = __builtin_popcountll(i);
        if (b % 2)ans += r;
        else ans -= r;
        //debug(st,en,a,i,j,cnt)
        //debug(b%2,p,q,r,ans)
    }
    return ans;
}
int main()
{
    //IO;
    //while(1)
    //READ;WRITE;
    {
    freopen("inF.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
        ll a = 1, b = 0, c = 0, d, e, f, g, i, j, k, l, m, p, q, r, u, w, t, tc = 1, in, loc, val, sz, lo, hi, mid, mn = MAX, mx = 0, sum = 0, ans = 0;
//    cout<<pr.size();
//    fr(i,pr.size())
//    {
//        a*=pr[i];
//        debug(i,pr[i],a,log10(a));
//    }

        cin >> tc;
        rep(t, tc)
        {
            cin >> a >> b >> m;
            if (a > b)swap(a, b);
            d = b - a;
            v.clear();
            for (i = 0; i < pr.size() && pr[i] <= d; i++)
            {
                if (d % pr[i] == 0)v.pb(pr[i]);
            }

            l = v.size();
            //fr(i,l){debug(i,v[i])}
            //debug(l)
            TC(t);
            ll res1 = m + 1 - fun(l, a - 1, a + m);
            ll res = 0;
            //cout << a << " " << b << " " << m << endl;
            for (int i = 0; i <= m; i++) {
                if (gcd(a + i, b + i) == 1) {
                    res++;
                    //cout << a + i << " " << b + i << endl;
                }
            }
            if (res != res1) {
                cout << a << " " << b << " " << m << endl;
            }
        }
    }
    return 0;
}

/*
99
3 25 50
4 54 50
33 44 50
2 56789 50
4567 5678999 50
1 1000000000011 50
2 1000000000000 50
*/
/// Check for constraint 0 or 1?
/// Division MOD needs BigMod(a,n-2)
/// long long or double? sqrt or division will work fine??
/// sort(begin(v), end(v), [] (int a, int b) { return a > b; });    /// Lambda Function for manual Sort
