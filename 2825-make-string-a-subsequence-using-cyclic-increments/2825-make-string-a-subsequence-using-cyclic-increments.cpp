class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int it1=0,it2=0;
        while(it1<str1.size()&&it2<str2.size())
        {
            if(str1[it1]==str2[it2])
            {
                it1++;
                it2++;
                continue;
            }
            char ch=str1[it1];
            if(ch=='z')
                ch='a';
            else 
                ch++;
            if(str2[it2]==ch)
            {
                it1++;
                it2++;
                continue;
            }
            it1++;
        }
        return it2==str2.size();
    }
};