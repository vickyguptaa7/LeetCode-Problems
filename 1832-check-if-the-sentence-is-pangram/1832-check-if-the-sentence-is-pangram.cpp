class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>alpha(26,0);
        for(auto x:sentence)
        {
            alpha[x-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(alpha[i]==0)return false;
        }
        return true;
    }
};