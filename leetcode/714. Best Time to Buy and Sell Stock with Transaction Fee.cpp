class Solution {
public:
    int dp[50005][3];
    int go(int idx,int stock,vector<int>& prices,int fee){
        if(idx >= prices.size())
            return 0;
        if(dp[idx][stock]!=-1)
            return dp[idx][stock];
        int ret=0;
        if(stock==0){//have to buy
            ret= -prices[idx]+go(idx+1,stock+1,prices,fee);
            ret=max(ret,go(idx+1,stock,prices,fee));
        }
        else{
            ret=prices[idx]-fee+go(idx+1,stock-1,prices,fee);
            ret=max(ret,go(idx+1,stock,prices,fee));
        }
        return dp[idx][stock]=ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof dp);
        return go(0,0,prices,fee);
    }
};