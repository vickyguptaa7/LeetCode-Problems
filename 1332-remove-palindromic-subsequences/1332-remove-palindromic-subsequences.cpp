class Solution {
public:
    int removePalindromeSub(string s) {
        int size=s.length();
        int it1=(size-1)/2;
        int it2=(size)/2;
        
        while(it1>=0&&it2<size)
        {
            if(s[it1]!=s[it2])
            {
                return 2;
            }
            it1--;
            it2++;
        }
        return 1;
    }
};