class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()<num2.size())swap(num1,num2);
        reverse(num2.begin(),num2.end());
        while(num2.size()<num1.size())
            num2.push_back('0');
        reverse(num2.begin(),num2.end());
        int n = num2.size(),carry=0;
        string res="";
        for(int i=n-1;i>=0;i--){
            int d = carry+(num1[i]-'0')+(num2[i]-'0');
            if(d>9){
                carry=1;
                d-=10;
            }
            else{
                carry=0;
            }
            char ch = '0' + d;
            res.push_back(ch);
        }
        if(carry)res.push_back('1');
        reverse(res.begin(),res.end());
        
        return res;
    }
};