class Solution {
    
    void mergeArr(vector<pair<int,int>>&arr,int start,int end,vector<int>&result)
    {
        int mid=(start+end)/2;
        vector<pair<int,int>>temp;
        int it1=mid,it2=end;
        while(it1>=start&&it2>=mid+1)
        {
            if(arr[it1].first>arr[it2].first)
            {
                result[arr[it1].second]+=it2-mid;
                it1--;
            }
            else
            {
                it2--;
            }
        }
        it1=start,it2=mid+1;    
        while(it1<=mid&&it2<=end)
        {
            if(arr[it1].first>arr[it2].first)
            {
                temp.push_back(arr[it2]);
                it2++;
            }
            else
            {
                temp.push_back(arr[it1]);
                it1++;
            }
            
        }
        while(it1<=mid)
        {
            temp.push_back(arr[it1]);
            it1++;
        }
        while(it2<=end)
        {
            temp.push_back(arr[it2]);
            it2++;
        }
        for(int i=start;i<=end;i++)arr[i]=temp[i-start];
    }
    
    void mergeSort(vector<pair<int,int>>&arr,int start,int end,vector<int>&result)
    {
        if(start>=end)
            return;
        int mid=(start+end)/2;
        mergeSort(arr,start,mid,result);
        mergeSort(arr,mid+1,end,result);
        mergeArr(arr,start,end,result);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>narr;
        for(int i=0;i<nums.size();i++)narr.push_back({nums[i],i});
        vector<int>result(nums.size(),0);
        mergeSort(narr,0,nums.size()-1,result);
        return result;
    }
};