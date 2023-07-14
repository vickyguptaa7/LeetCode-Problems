class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]==target)
            {
                return mid;
            }
            else if(arr[mid]>=arr[0])
            {
                if(arr[0]<=target&&arr[mid]>target)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(arr.back()>=target&&arr[mid]<target)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            
        }
        return -1;
    }
};