class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {
        int len=nums.size();
        vector<int>triplets(3,2147483647);
        for(int i=0;i<len;i++)
        {
            int index=lower_bound(triplets.begin(),triplets.end(),nums[i])-triplets.begin();
            if(index>=2)return true;
            else
            {
                triplets[index]=nums[i];
            }
            
        }
        return false;
        
    }
};