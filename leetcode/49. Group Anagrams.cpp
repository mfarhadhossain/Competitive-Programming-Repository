class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int curr=1, sz = strs.size();
        map<string,int>Map;
        int rs=0;
        for(int i=0;i<sz;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(Map[s]==0){
                Map[s]=curr++;
            }
            
        }
        
        vector<vector<string>>res(curr-1);
            for(int j=0;j<sz;j++){
                string s = strs[j];
                sort(s.begin(),s.end());
                int i = Map[s]-1;
                res[i].push_back(strs[j]);
                //cerr<<"for "<<strs[j]<<" key = "<<i<<endl;
            }
        return res;
    }
};