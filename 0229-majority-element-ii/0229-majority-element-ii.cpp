class Solution {
public:
    
    int isMajority(int num,vector<int>&nums)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt+=nums[i]==num;
        }
        return cnt>(nums.size()/3); 
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int num1=nums[0],num2=1e9+1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==num1)
            {
                cnt1++;
            }
            else if(nums[i]==num2)
            {
                cnt2++;
            }
            else if(cnt1==0)
            {
                num1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                num2=nums[i];
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int>res;
        if(isMajority(num1,nums))
            res.push_back(num1);
        if(isMajority(num2,nums))
            res.push_back(num2);
        return res;
    }
};