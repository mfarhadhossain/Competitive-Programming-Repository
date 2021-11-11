class Solution {
public:
    string fun(string s){
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(tmp.size()){
                    tmp.pop_back();
                }
            }
            else{
                tmp.push_back(s[i]);
            }
        }
        return tmp;
    }
    bool backspaceCompare(string s, string t) {
        return fun(s)==fun(t);
    }
};