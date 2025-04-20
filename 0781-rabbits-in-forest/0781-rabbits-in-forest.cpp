class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int>freq(1000,0);
        for(auto answer:answers)
        {
            freq[answer]++;
        }
        int ans=0;
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]==0)continue;
            ans+=(i+1<freq[i]?ceil(freq[i]/(i+1.0))*(i+1):i+1);
        }
        return ans;
    }
};