class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(auto &num:nums)
        {
            int indx=lower_bound(temp.begin(),temp.end(),num)-temp.begin();
            if(indx==temp.size())
            {
                temp.push_back(num);
            }
            else 
            {
                temp[indx]=num;
            }
        }
        return temp.size();
    }
};