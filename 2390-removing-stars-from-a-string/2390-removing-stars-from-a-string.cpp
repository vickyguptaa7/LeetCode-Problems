class Solution {
public:
    string removeStars(string s) {
        reverse(s.begin(),s.end());
        string ans;
        int sc=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')sc++;
            else 
            {
                if(sc!=0)
                {
                    sc--;
                    continue;
                }
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};