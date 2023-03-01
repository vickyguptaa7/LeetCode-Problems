class Solution {
public:
    
    void mergeArr(vector<int>&nums,int left,int mid,int right)
    {
        vector<int>leftArr(mid-left+1,0),rightArr(right-mid,0);
       
        vector<int>temp(right-left+1,0);
        int it1=left,it2=mid+1,it3=0;
        while(it1<=mid&&it2<=right)
        {
            if(nums[it1]<nums[it2])
            {
                temp[it3]=nums[it1];
                it1++;
                it3++;
            }
            else 
            {
                temp[it3]=nums[it2];
                it2++;
                it3++;
            }
        }
        while(it1<=mid)
        {
            temp[it3]=nums[it1];
            it3++;
            it1++;
        }
        while(it2<=right)
        {
            temp[it3]=nums[it2];
            it3++;
            it2++;
        }
        for(int i=0;i<temp.size();i++)
            nums[i+left]=temp[i];
    }
    
    void mergeSort(vector<int>&nums,int left,int right)
    {
        if(left>=right)
            return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        mergeArr(nums,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,(int)nums.size()-1);
        return nums;
    }
};