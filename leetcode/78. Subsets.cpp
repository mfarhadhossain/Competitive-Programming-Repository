class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>& nums, int i, int n, vector<int> ret) {
        if (i >= n) {
            res.push_back(ret);
            return;
        }
        ret.push_back(nums[i]);
        solve(nums, i + 1, n, ret);
        ret.pop_back();
        solve(nums, i + 1, n, ret);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        solve(nums , 0 , nums.size(), {});
        return res;
    }
};