class Solution {
public:
    int dp[303][5003];
    int go(int idx, int curr, vector<int>& coins) {
        if (curr < 0) return 0;
        if (idx == coins.size()) {
            return curr == 0;
        }
        if (dp[idx][curr] != -1)
            return dp[idx][curr];
        return dp[idx][curr] = go(idx, curr - coins[idx], coins) + go(idx + 1, curr, coins);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof dp);
        int ret = go(0, amount, coins);
        //if(ret==1e9)ret=-1;
        return ret;
    }
};