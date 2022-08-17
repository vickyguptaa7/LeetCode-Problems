class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>mp={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        set<string>ans;
        for(auto word:words)
        {
            string code;
            for(auto ch:word)
            {
                code+=mp[ch-'a'];
            }
            ans.insert(code);
        }
        return ans.size();
    }
};