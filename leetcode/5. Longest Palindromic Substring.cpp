class Solution {
public:
    int dp[1001][1001];
    bool ispalindrome(int l,int r,string &s){
        if(l>=r)
            return 1;
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        if(s[l]==s[r])
            return dp[l][r]=ispalindrome(l+1,r-1,s);
        return dp[l][r]=0;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof dp);
        int n = s.size();
        int b=0,e=0,maximum=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(ispalindrome(i,j,s)==1){
                    if(j-i+1 > maximum){
                        maximum=j-i+1;
                        b=i,e=j;
                    }
                }
            }
        }
        return s.substr(b,maximum);
    }
};