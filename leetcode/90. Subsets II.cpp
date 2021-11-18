class Solution {
public:
	vector<vector<int>>res;
	map< vector<int> , int > M;
	void solve(vector<int>& nums, int i, int n, vector<int> ret) {
		if (i >= n) {
			sort(ret.begin(), ret.end());
			if (M[ret] == 0) res.push_back(ret);
			M[ret] = 1;
			return;
		}
		ret.push_back(nums[i]);
		solve(nums, i + 1, n, ret);
		ret.pop_back();
		solve(nums, i + 1, n, ret);
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		res.clear();
		M.clear();
		solve(nums , 0 , nums.size(), {});
		return res;
	}
};