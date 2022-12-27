class Solution {
public:
    int similarPairs(vector<string>& words) {
        int result=0;
        for(int i=0;i<words.size();i++)
        {
            set<char>mset(words[i].begin(),words[i].end());
            for(int j=i+1;j<words.size();j++)
            {
                set<char>hset(words[j].begin(),words[j].end());
                if(hset==mset)
                    result++;
            }
        }
        return result;
    }
};