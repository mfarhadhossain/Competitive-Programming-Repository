class Solution {
public:
    int dp[111][2][2];
    int go(int idx,int pr,int f,vector<int>& nums){
        if(idx==nums.size())return 0;
        if(dp[idx][pr][f]!=-1)
            return dp[idx][pr][f];
        int ret=go(idx+1,0,f,nums);
        if(pr==0){
            if(idx==nums.size()-1&&f==0)
            ret=max(ret,nums[idx]+go(idx+1,1,f,nums));  
            else if(idx==0){
                ret=max(ret,nums[idx]+go(idx+1,1,1,nums));  
            }
            else if(idx>0&& idx<nums.size()-1){
                ret=max(ret,nums[idx]+go(idx+1,1,f,nums));
            }
        }
        return dp[idx][pr][f]=ret;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return go(0,0,0,nums);
    }
};