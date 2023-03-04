class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        map<int,int>freq;
        long long subArrayCount=0;
        int size=nums.size(),prev=0;
        vector<int>problematicIndx;
        for(int i=0;i<size;i++)
            if(minK>nums[i]||maxK<nums[i])
                problematicIndx.push_back(i);
        
        for(int i=0;i<size;i++)
        {
            if(nums[i]>=minK&&nums[i]<=maxK)
            {
                freq[nums[i]]++;
            }
            else
            {
                prev=i+1;
                freq.clear();
            }
            while(freq.begin()->first==minK&&freq.rbegin()->first==maxK)
            {
                auto indx=lower_bound(problematicIndx.begin()
                                      ,problematicIndx.end(),i);
                if(indx==problematicIndx.end())
                    subArrayCount+=size-i;
                else
                    subArrayCount+=*indx-i;
                
                freq[nums[prev]]--;
                if(freq[nums[prev]]==0)
                    freq.erase(nums[prev]);
                prev++;
            }
        }
        return subArrayCount;
    }
};