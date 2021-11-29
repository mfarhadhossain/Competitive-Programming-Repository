class Solution {
public:
    int dp[13][10003];
    int go(int idx, int curr, vector<int>& coins) {
        if (curr < 0)return 1e9;
        if (curr == 0) return 0;
        if (dp[idx][curr] != -1)
            return dp[idx][curr];
        if (idx == coins.size()) {
            if (curr == 0)
                return 0;
            return 1e9;
        }
        return dp[idx][curr] = min(1 + go(idx, curr - coins[idx], coins), go(idx + 1, curr, coins));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ret = go(0, amount, coins);
        if (ret == 1e9)ret = -1;
        return ret;
    }
};