class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int res=0,min=1e9;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int strt=i+1,end=n-1;
            while(strt<end)
            {
                int find=nums[i]+nums[strt]+nums[end];
                if(find-target==0)
                {
                    return find;
                }
                else if(find-target>0)
                {
                    if(abs(find-target)<min)
                    {
                        res=find;
                        min=abs(find-target);
                    }
                    end--;
                }
                else
                {
                    if(abs(find-target)<min)
                    {
                        res=find;
                        min=abs(find-target);
                    }
                    strt++;
                }
            }
        }
        return res;
    }
};