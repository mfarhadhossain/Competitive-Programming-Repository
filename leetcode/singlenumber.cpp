class Solution {
public:
    static int fun(int x,int y)
    {
        return x^y;
    }
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(),nums.end(),0,fun);
    }
};