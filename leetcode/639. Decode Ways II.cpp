class Solution {
public:
    using ll = long long int;
    static const int MOD = 1e9 + 7;
    ll dp[100001][11];
    int go(int idx, int pr, string &s) {
        if (idx >= s.size())
            return pr == 0;
        if (dp[idx][pr] != -1)
            return dp[idx][pr];
        ll ret = 0;
        if (s[idx] == '*') {
            for (int i = 1; i <= 9; i++) {
                s[idx] = (char)('0' + i);
                if (pr) { // previous digit is open

                    int num = pr * 10 + s[idx] - '0';
                    if (num <= 26 && num >= 0)
                        ret += go(idx + 1, 0, s) % MOD;
                }
                else {
                    ret += go(idx + 1, i, s) % MOD;
                    ret += go(idx + 1, 0, s) % MOD;
                }
            }
            s[idx] = '*';
        }

        else {
            if (pr) { // previous digit is open

                int num = pr * 10 + s[idx] - '0';
                if (num <= 26 && num >= 0)
                    ret += go(idx + 1, 0, s) % MOD;
            }
            else {
                if (s[idx] != '0') {
                    ret += go(idx + 1, s[idx] - '0', s) % MOD;
                    ret += go(idx + 1, 0, s) % MOD;
                }
            }
        }

        return dp[idx][pr] = ret % MOD;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return go(0, 0, s);
    }
};