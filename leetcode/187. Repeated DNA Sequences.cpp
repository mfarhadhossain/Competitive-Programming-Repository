class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        int n = s.size();
        map<string,int>MAP;
        for(int i=0;i<n;i++){
            string tmp="";
            int j=i,cnt=0;
            while(j<n){
                tmp.push_back(s[j]);
                j++;
                cnt++;
                if(cnt==10)break;
            }
            if(tmp.size()!=10)continue;
            
            if(MAP[tmp]==1){
                res.push_back(tmp);
            }
            MAP[tmp]++;
        }
        return res;
    }
};