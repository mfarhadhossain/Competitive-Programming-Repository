class Solution {
public:
    int dp[5005][3];
    int go(int idx,int stock,vector<int>& prices){
        if(idx >= prices.size())
            return 0;
        if(dp[idx][stock]!=-1)
            return dp[idx][stock];
        int ret=0;
        if(stock==0){//have to buy
            ret= -prices[idx]+go(idx+1,stock+1,prices);
            ret=max(ret,go(idx+1,stock,prices));
        }
        else{
            ret=prices[idx]+go(idx+2,stock-1,prices);
            ret=max(ret,go(idx+1,stock,prices));
        }
        return dp[idx][stock]=ret;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return go(0,0,prices);
    }
};