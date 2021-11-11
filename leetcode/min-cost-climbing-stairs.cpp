// recursive
class Solution {
public:
    int dp[1111];
    int go(int idx,vector<int>&cost){
        if(idx>=cost.size())return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx]=min(go(idx+1,cost)+cost[idx], go(idx+2,cost)+cost[idx]);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        return min(go(0,cost),go(1,cost));
    }
};
// iterative
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+5);
        for(int i=2;i<=n;i++)
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        //return min(dp[n-1],dp[n-2]);
        return dp[n];
    }
};