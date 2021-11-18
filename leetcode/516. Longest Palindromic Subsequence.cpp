class Solution {
public:
    int dp[1001][1001];
    int go(int l,int r,string &s){
        if(l>r)return 0;
        if(l==r)return dp[l][r]=1;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ret=0;
        if(s[l]==s[r]){
            ret=2+go(l+1,r-1,s);
        }
        else{
            ret=max(ret,go(l+1,r,s));
            ret=max(ret,go(l,r-1,s));
        }
        return dp[l][r] = ret;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof dp);
        return go(0,(int)s.size()-1,s);
    }
};