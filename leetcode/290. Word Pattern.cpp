class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        stringstream ss(s);
        map<string,char>map_string;
        map<char,string>map_char;
        string temp;
        int i=0;
        while(ss>>temp){
            
            if(map_char.find(pattern[i])!=map_char.end()){
                if(temp!=map_char[pattern[i]])
                    return false;
            }
            else if(map_string.find(temp)!=map_string.end()){
                if(pattern[i]!=map_string[temp])
                    return false;
            }
            else{
                map_char[pattern[i]]=temp;
                map_string[temp]=pattern[i];
            }
            
            i++;
        }
        if(i<n)return false;
        return true;
    }
};