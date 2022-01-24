class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n=word.length();
        if(n==1)return 1;
        bool first_Cap=false,second_Cap=false;
        if(word[0]>=65&&word[0]<=90)first_Cap=true;
        if(word[1]>=65&&word[1]<=90)second_Cap=true;
        if(!first_Cap&&second_Cap)return false;
        for(int i=2;i<n;i++)
        {
            if(!first_Cap&&word[i]>=65&&word[i]<=90)return false;
            if(first_Cap&&second_Cap&&(word[i]<65||word[i]>90))return false;
            if(first_Cap&&!second_Cap&&word[i]>=65&&word[i]<=90)return false;
        }
    return true;
    }
};