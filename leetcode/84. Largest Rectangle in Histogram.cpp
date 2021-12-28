class Solution {
private:
	const static int MAX = 1e5 + 3;
	pair<long long, long long> TREE[4 * MAX];
public:
	void build(int seg, int l, int r, vector<int>& heights) {
		if (l == r) {
			TREE[seg] = make_pair(heights[l], l);
			return;
		}
		int mid = (l + r) / 2;
		build(seg * 2, l, mid, heights);
		build(seg * 2 + 1, mid + 1, r, heights);
		if (TREE[seg * 2].first < TREE[seg * 2 + 1].first) {
			TREE[seg] = TREE[seg * 2];
		}
		else {
			TREE[seg] = TREE[seg * 2 + 1];
		}
	}
	pair<long long, long long> query(int seg, int l, int r, int L, int R) {
		if (l > R || r < L)return {1e9, 0};
		if (l >= L && r <= R)
		{
			return TREE[seg];
		}
		int mid = (l + r) / 2;
		pair<long long, long long> x = query(2 * seg, l, mid, L, R);
		pair<long long, long long> y = query(2 * seg + 1, mid + 1, r, L, R);
		if (x.first < y.first)return x;
		return y;
	}
	int solve(int l, int r, vector<int>& heights) {
		if (l > r)return -1;
		if (l == r)return heights[l];
		auto ret = query(1, 1, heights.size() - 1, l, r);
		int min_id = ret.second;
		long long y, z, x = solve(l, min_id - 1, heights);
		y = solve(min_id + 1, r, heights);
		z = (r - l + 1) * ret.first;
		return max({x, y, z});
	}
	int largestRectangleArea(vector<int>& heights) {
		reverse(heights.begin(), heights.end());
		heights.push_back(0);
		reverse(heights.begin(), heights.end());
		build(1, 1, heights.size() - 1, heights);
		return solve(1, heights.size() - 1, heights);
	}
};