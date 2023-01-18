/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr,int n)
    {
        int low=1,high=n-1,ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int v1=mountainArr.get(mid);
            int v2=mountainArr.get(mid+1);
            int v3=mountainArr.get(mid-1);
            if(v1>v2&&v1>v3)
            {
                return mid;
            }
            else if(v1<v2)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return 0;
    }
    int binarySearch(int low,int high,int target,MountainArray &arr,
                     bool isInc=true)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            int val=arr.get(mid);
            if(val==target)
            {
                return mid;
            }
            else if(val>target)
            {
                if(isInc)
                    high=mid-1;
                else 
                    low=mid+1;
            }
            else
            {
                if(isInc)
                    low=mid+1;
                else 
                    high=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peakIndx=findPeak(mountainArr,n-1);
        int indx=binarySearch(0,peakIndx,target,mountainArr);
        if(indx!=-1)
            return indx;
        indx=binarySearch(peakIndx+1,n-1,target,mountainArr,false);
        return indx;
    }
};