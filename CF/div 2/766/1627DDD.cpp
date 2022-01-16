#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
typedef pair<int, int> pii;
const int MAXN = 1e6 + 10, MOD = 1e9 + 7;
int spf[MAXN], ar[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
int main()
{
    sieve();

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        vector <int> p = getFactorization(ar[i]);

        cout << "prime factorization for " << ar[i] << " : ";

        for (int i = 0; i < p.size(); i++)
            cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}