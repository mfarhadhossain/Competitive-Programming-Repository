class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int res=0,mn=1e9;
        for(int i=0;i<prices.size();i++){
           res=max(res,prices[i]-mn);
           mn=min(mn,prices[i]);
       }
        return res;
    }
};