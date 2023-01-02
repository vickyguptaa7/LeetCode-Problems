class Solution {
public:
    bool detectCapitalUse(string word) {
        int uc=0,lc=0;
        for(auto x:word)
        {
            if(x>='A'&&x<='Z')
            {
                uc++;
            }
            else if(x>='a'&&x<='z')
            {
                lc++;
            }
        }
        if(lc==word.size()||uc==word.size())
            return true;
        if(uc==1&&word[0]>='A'&&word[0]<='Z')
            return true;
        return false;
    }
};