class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        if(s==goal)
        {
            int isPresent=0;
            for(auto x:s)
            {
                if((isPresent&(1<<(x-'a'))))
                    return true;
                isPresent|=(1<<(x-'a'));
            }
            return false;
        }
        int count=0;
        vector<int>freq(27,0);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
            freq[goal[i]-'a']--;
            if(s[i]!=goal[i])count++;
        }

        for(int i=0;i<freq.size();i++)
            if(freq[i]!=0)
                return false;

        return count==2;
    }
};