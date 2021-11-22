class Solution {
public:
    using ll = long long int;
    vector<ll>res;
    inline ll LPOW(ll a, ll e)
    {
        ll num = 1;
        while (e)
        {
            if (e % 2)
            {
                num = num * a;
            }
            e /= 2;
            if (a <= 2e9)a = a * a;
            else return 0;
        }
        if (num > 2e9)return 0;
        return num;
    }
    int nthUglyNumber(int n) {
        int f = 1;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                for (int k = 0; k < 32; k++) {
                    ll num = LPOW(2, i);

                    if (num >= 1 && num <= 1e18);
                    else {break;}
                    num *= LPOW(3, j);
                    if (num >= 1 && num <= 1e18);
                    else {break;}
                    num *= LPOW(5, k);
                    if (num >= 1 && num <= 1e18)res.push_back(num);
                    else {break;}
                }
            }
        }
        sort(res.begin(), res.end());
        return res[n - 1];
    }
};
class Solution {
public:
    using ll = unsigned long long int;
    int nthUglyNumber(int n) {
        vector<ll>dp(n + 10);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = min({dp[a] * 2, dp[b] * 3, dp[c] * 5});
            if (dp[i] == dp[a] * 2)a++;
            if (dp[i] == dp[b] * 3)b++;
            if (dp[i] == dp[c] * 5)c++;
        }
        return dp[n - 1];
    }
};