/*

    author : s@if

*/

#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define         NIL             -1
#define         INF             1e9
#define         EPS             1e-9
#define         SAIF            main
#define         fi              first
#define         sec             second
#define         MAX             INT_MAX
#define         ll              long long
#define         PI              acos(-1.0)
#define         MOD             1000000007
#define         PLL             pair<ll,ll>
#define         PII             pair<int,int>
#define         ull             unsigned long long
#define         For(i,a,b)      for(int i=a;i<=(int)b;i++)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//         tree_order_statistics_node_update> new_data_set;

//*find_by_order(k)  gives the kth element;
//order_of_key(item)   gives the index(number of element strictly less than item) of item;

inline int in() {int x; scanf("%d", &x); return x; }
bool Check(int N , int pos) {   return (bool) (N & (1 << pos));}
int Set(int N, int pos) {   return N = N | (1 << pos);}

int fx[] = { +0, +0, +1, -1, -1, +1, -1, +1}; // King's move
int fy[] = { -1, +1, +0, +0, +1, +1, -1, -1};
int hx[] = { -2, -2, -1, +1, +2, +2, -1, +1}; // Knight's move
int hy[] = { +1, -1, +2, +2, -1, +1, -2, -2};
int dx[] = { +1, -1, +0, +0};
int dy[] = { +0, +0, +1, -1};

const int MAXN = (int)1e5 + 9;

string s, ch;
ll base1 = 247, base2 = 347, MOD1 = 1000000007, MOD2 = 1000000009, L;
map<ll, ll>h1, h2; ll dp[MAXN];

ll solve(ll i)
{
    if (i >= L) return 0;

    if (dp[i] != -1LL) return dp[i];

    ll ret = INF; ll u = 0, v = 0; ll power1 = 1, power2 = 1;

    for (int j = 0; i + j < L; j++)
    {
        ll x = ((s[i + j] - 'a' + 1) * power1) % MOD1;
        u = (u + x) % MOD1;

        x = ((s[i + j] - 'a' + 1) * power2) % MOD2;
        v = (v + x) % MOD2;

        power1 = (power1 * base1) % MOD1;
        power2 = (power2 * base2) % MOD2;

        if (h1[u] > 0 && h2[v] > 0) {
            ret = min(ret, 1 + solve(i + j + 1));
        }
    }

    return dp[i] = ret;
}

int main()
{
    ll i, j, k, l, m, n, p, q, x, y, u, v, w, r, tc, t, d;

    cin >> tc; t = 0;
    while (tc--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> ch;
            l = ch.size();

            u = v = 0; ll power1 = 1, power2 = 1;

            for (j = 1; j <= l; j++)
            {
                x = ((ch[j - 1] - 'a' + 1) * power1) % MOD1;
                u = (u + x) % MOD1;

                x = ((ch[j - 1] - 'a' + 1) * power2) % MOD2;
                v = (v + x) % MOD2;

                power1 = (power1 * base1) % MOD1;
                power2 = (power2 * base2) % MOD2;
            }

            h1[u]++; h2[v]++;
        }

        cin >> s; L = s.size();

        cout << "Case " << ++t << ": ";

        memset(dp, -1, sizeof(dp));
        ll ans =  solve(0);
        if (ans >= INF) cout << "impossible\n";
        else cout << ans << endl;

        h1.clear(); h2.clear();
    }

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
