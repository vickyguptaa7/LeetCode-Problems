class Solution {
public:
// all three same -> same number
// any two repeats -> non repeat numer
// all three unique -> unique no

    int uniqueXorTriplets(vector<int>& nums) {
        vector<int>xr(5000,0);        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                xr[nums[j]^nums[i]]=1;
            }
        }
        vector<int>freq(5000,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<5000;j++)
            {
                if(!xr[j])continue;
                freq[nums[i]^j]=1;
            }
        }
        return accumulate(freq.begin(),freq.end(),0ll);
    }
};
// 0, 2 
//