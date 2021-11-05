#include<bits/stdc++.h>
using namespace std;
char inv(char ch){
    if(ch==')')return '(';
    if(ch=='>')return '<';
    if(ch==']')return '[';
    return '{';
}
int main (){
    string s;cin>>s;

    stack<char>stk;

    int res=0;

    for(int i=0;i<s.size();i++){

        if(s[i]=='(' || s[i]=='{'|| s[i]=='<'|| s[i]=='['){
            stk.push(s[i]);
        }
        else{
            if(stk.empty()){
                cout<<"Impossible\n";
                return 0;
            }
            else{
                if(stk.top()==inv(s[i])){
                        stk.pop();
                }
                else{
                    res++;
                    stk.pop();
                }
            }
        }
    }
    if(stk.size())cout<<"Impossible\n";
    else cout<<res<<endl;
    return 0;
}
