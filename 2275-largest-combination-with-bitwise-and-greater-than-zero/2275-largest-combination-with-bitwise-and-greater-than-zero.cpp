class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>bits(31,0);
        for(int i=0;i<candidates.size();i++)
        {
            int temp=candidates[i];
            int j=0;
            while(temp>0)
            {
                if(temp%2==1)bits[j]++;
                temp/=2;
                j++;
            }
        }
        int ans=*max_element(bits.begin(),bits.end());
        return ans;
    }
};