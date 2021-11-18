class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        map<vector<int>, int>map;
        sort(nums.begin(), nums.end());
        do {
            if (map[nums] == 0)
                res.push_back(nums);
            map[nums] = 1;
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};