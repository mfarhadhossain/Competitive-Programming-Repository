class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<vector<int>>freq;
        vector<int>f(26),g(26);
        int n = s.size();
        for(int i=0;i<p.size();i++){
            g[p[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            f[s[i]-'a']++;
            freq.push_back(f);
        }
        int len = p.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            vector<int>h(26);
            int l = i , r = i + len-1;
            if(r>=n)break;
            for(int j=0;j<26;j++){
                if(l-1>=0)h[j] = freq[r][j]-freq[l-1][j];
                else h[j] = freq[r][j];
            }
            int bad=0;
            for(int j=0;j<26;j++){
                if(h[j]!=g[j]){bad=1;break;}
            }
            if(bad==0)res.push_back(i);
        }
        return res;
    }
};