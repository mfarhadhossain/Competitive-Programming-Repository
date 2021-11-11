class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix_mul(n+5),suffix_mul(n+5);
        prefix_mul[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix_mul[i]=nums[i]*prefix_mul[i-1];
        }
        suffix_mul[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_mul[i]=nums[i]*suffix_mul[i+1];
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(i==0){
                res.push_back(suffix_mul[i+1]);
            }
            else if(i==n-1){
                res.push_back(prefix_mul[i-1]);
            }
            else res.push_back(prefix_mul[i-1]*suffix_mul[i+1]);
        }
        return res;
    }
};