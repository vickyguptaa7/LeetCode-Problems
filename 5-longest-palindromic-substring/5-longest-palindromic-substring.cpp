class Solution {
public:
    pair<int,int> Pallindrome(string s,int l,int r)
    {
        while(l>=0&&r<s.size())
        {
            if(s[l]!=s[r])return {l+1,r-1};
            l--;
            r++;
        }
        return {l+1,r-1};
    }
    string longestPalindrome(string s) {
        if(s.size()==1)return s;
        string res;
        pair<int,int>size={0,0};
        for(int i=1;i<s.size();i++)
        {
            pair<int,int>curSize=Pallindrome(s,i-1,i+1);
            if(curSize.second-curSize.first>size.second-size.first)
            {
                size=curSize;
            }
            curSize=Pallindrome(s,i-1,i);
            if(curSize.second-curSize.first>size.second-size.first)
            {
                size=curSize;
            }
        }
        for(int i=size.first;i<=size.second;i++)
        {
            res+=s[i];
        }
        return res;
    }
};