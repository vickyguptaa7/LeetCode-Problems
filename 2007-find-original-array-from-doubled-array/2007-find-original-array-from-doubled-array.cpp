class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>freq;
        vector<int>res;
        sort(changed.begin(),changed.end(),greater<int>());
        for(int i=0;i<changed.size();i++)
        {
            if(freq.count(changed[i]))
            {
                freq[changed[i]]--;
                if(freq[changed[i]]==0)
                {
                    freq.erase(changed[i]);
                }
                res.push_back(changed[i]);
            }
            else
            {
                if(changed[i]&1)
                {
                    return {};
                }
                else
                {
                    freq[changed[i]/2]++;
                }
            }
        }
        if(freq.empty())return res;
        return {};
    }
};