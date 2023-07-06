class Solution {
public:
    
    void merge(vector<int>&nums,int low,int mid,int high,int &count)
    {
        vector<int>temp(high-low+1,0);
        int it1=0,it2=low,it3=mid+1,size=high-low+1;
        
        int iter=low;
        for(int i=mid+1;i<=high;i++)
        {
            while(iter<mid+1&&nums[iter]<=nums[i]*2ll)
            {
                iter++;
            }
            if(nums[iter]>nums[i]*2ll)
                count+=mid+1-iter;
        }
        
        while(it2<=mid&&it3<=high)
        {
            if(nums[it2]>=nums[it3])
            {
                temp[it1]=nums[it3];
                it3++;
                it1++;
            }
            else
            {
                temp[it1]=nums[it2];
                it2++;
                it1++;
            }
        }
        while(it2<=mid)
        {
            temp[it1]=nums[it2];
            it2++;
            it1++;
        }
        while(it3<=high)
        {
            temp[it1]=nums[it3];
            it3++;
            it1++;
        }
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
    }
    
    void mergeSort(vector<int>&nums,int low,int high,int &count)
    {
        if(low>=high)
            return;
        int mid=(low+high)/2;
        mergeSort(nums,low,mid,count);
        mergeSort(nums,mid+1,high,count);
        merge(nums,low,mid,high,count);
    }
    
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergeSort(nums,0,(int)nums.size()-1,count);
        return count;
    }
};