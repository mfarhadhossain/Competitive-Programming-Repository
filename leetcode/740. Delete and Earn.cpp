class Solution {
public:
    int dp[10001][3];
    int go(int idx,int pr,vector<int>& cnt){
        if(idx>=cnt.size()){
            return 0;
        }
        if(dp[idx][pr]!=-1)
            return dp[idx][pr];
        int ret=0;
        if(pr==0){
            ret=idx*cnt[idx]+go(idx+1,1,cnt);
            
            ret=max(ret,go(idx+1,0,cnt));
        }
        else{
            
            ret=max(ret,go(idx+1,0,cnt));
        }
        //cout<<idx<<" "<<ret<<endl;
        return dp[idx][pr]=ret;
    }
    int deleteAndEarn(vector<int>& nums) {
        //puts("");
        memset(dp,-1,sizeof dp);
        vector<int>cnt(10001);
        for(auto x:nums){
            cnt[x]++;
        }
        return go(1,0,cnt);
    }
};