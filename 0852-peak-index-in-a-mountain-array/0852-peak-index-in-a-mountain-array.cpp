class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size()-1,ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>arr[mid+1])
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};