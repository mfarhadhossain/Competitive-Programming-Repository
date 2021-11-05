#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    int n;cin>>n;
    while(n--){
        cin>>s;
        if(s.size()==1)cout<<"1";
        else{
            vector<string>haha;
            string curr="",prev="";
            for(int i=0;i<s.size();i++){
                if(curr.size()==0){
                    curr=s[i];
                    continue;
                }
                if(s[i]< curr.back()){
                    prev = curr;

                    haha.push_back(curr);
                    curr = s[i];
                }
                else{
                    curr.push_back(s[i]);
                }
            }
            if(curr.size())haha.push_back(curr);
            int bad=0;
            for(int i=0;i<haha.size()-1;i++){
                if(haha[i]>haha[i+1]){
                    bad = 1;
                    break;
                }
            }
            if(bad==1)cout<<"0";
            else      cout<<"1";

        }
    }
    cout<<endl;
    return 0;
}
