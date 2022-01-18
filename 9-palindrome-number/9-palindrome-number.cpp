class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string str1=to_string(x);
        string str2=to_string(x);
        reverse(str2.begin(),str2.end());
        return (str1==str2);
    }
};