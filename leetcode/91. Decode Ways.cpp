class Solution {
public:
    int dp[101][11];
    int go(int idx, int pr, string &s) {
        if (idx >= s.size())
            return pr == 0;
        if (dp[idx][pr] != -1)
            return dp[idx][pr];
        int ret = 0;
        if (pr) { // previous digit is open
            int num = pr * 10 + s[idx] - '0';
            if (num <= 26 && num >= 0)
                ret = go(idx + 1, 0, s);
        }
        else {
            if (s[idx] != '0') {
                ret = go(idx + 1, s[idx] - '0', s);
                ret += go(idx + 1, 0, s);
            }
        }
        return dp[idx][pr] = ret;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return go(0, 0, s);
    }
};