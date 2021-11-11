class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>f;
        string unique="";
        for(auto ch:s){
            if(f[ch]==0){
                unique.push_back(ch);
            }
            f[ch]++;
        }
        vector<int>v,odd_f;
        for(auto ch:unique){
            v.push_back(f[ch]);
        }
        int res=0,odd_cnt=0;
        for(auto x:v){
            if(x&1){
                odd_cnt++;
            }
            res+=x;
        }
        if(odd_cnt)res-=(odd_cnt-1);
        return res;
    }
};