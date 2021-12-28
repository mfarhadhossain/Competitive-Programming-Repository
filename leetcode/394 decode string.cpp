class Solution {
public:
    int idx = 0;
    string power(int q, string s) {
        string res = "";
        while (q--)res += s;
        return res;
    }
    string solve(string s) {
        string res = "";
        while (idx < s.size()) {
            if (s[idx] == ']')return res;
            if (s[idx] >= '0' && s[idx] <= '9') {
                int d = 0, len = 0;
                for (int i = idx; i < s.size(); i++) {
                    if ( !(s[i] >= '0' && s[i] <= '9')) {
                        break;
                    }

                    d = d * 10 + s[i] - '0';
                    len++;
                }
                idx += len + 1;
                string ret = solve(s);
                res += power( d , ret);
            }
            else {
                res.push_back(s[idx]);
            }
            ++idx;
        }
        return res;
    }
    string decodeString(string s) {
        idx = 0;
        return solve(s);
    }
};