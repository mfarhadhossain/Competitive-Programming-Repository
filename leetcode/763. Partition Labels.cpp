class Solution {
public:
    bool overlaps(pair<int, int>&tmp, pair<int, int>&interval) {
        if (tmp.second < interval.first or interval.second < tmp.first)return 0;
        return 1;
    }
    pair<int, int> overlapped(pair<int, int>&tmp, pair<int, int>&interval) {
        pair<int, int>ret;
        ret.first = min(tmp.first, interval.first);
        ret.second = (max(tmp.second, interval.second));
        return ret;
    }
    vector<int>length(vector<pair<int, int>>&res) {
        vector<int>ret;
        for (int i = 0; i < res.size(); i++) {
            ret.push_back(1 + res[i].second - res[i].first);
        }
        return ret;
    }
    static bool sortfun(pair<int, int>&v1, pair<int, int>&v2) {
        return v1.first < v2.first;
    }

    vector<int> partitionLabels(string s) {
        vector<int>L(26, 1e9), R(26, -1e9);
        for (int i = 0; i < s.size(); i++) {
            L[s[i] - 'a'] = min(L[s[i] - 'a'], i + 1);
            R[s[i] - 'a'] = max(R[s[i] - 'a'], i + 1);
        }
        vector< pair<int, int> > intervals, res;
        for (int i = 0; i < 26; i++) {
            if (L[i] == 1e9) {
                continue;
            }
            intervals.push_back({L[i], R[i]});
        }
        sort(intervals.begin(), intervals.end(), sortfun);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            pair<int, int>tmp = res.back();
            if (overlaps(tmp, intervals[i])) {
                res.pop_back();
                res.push_back(overlapped(tmp, intervals[i]));
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return length(res);
    }
};