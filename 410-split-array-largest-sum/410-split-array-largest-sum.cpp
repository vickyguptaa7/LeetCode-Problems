class Solution {
public:    
    bool isValid(int sum,vector<int>&arr,int m)
    {
        int temp=0;
        for(int i=0;i<arr.size();i++)
        {
            temp+=arr[i];
            if(temp>sum)
            {
                  temp=arr[i];
                m--;
                if(m<0)return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0);
        int answer=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(mid,nums,m-1))
            {
                answer=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return answer;
    }
};