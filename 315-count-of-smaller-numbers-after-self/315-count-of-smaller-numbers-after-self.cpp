class Solution {
public:
    
    void merge(int s,int mid,int e,vector<pair<int,int>>&arr,vector<int>&result)
    {
        vector<pair<int,int>>temp(e-s+1);
        int i=s,j=mid+1,k=0;
        
        while(i<=mid&&j<=e)
        {
            if(arr[i].first<=arr[j].first)
            {
                temp[k++]=arr[j++];
            }
            else
            {
                result[arr[i].second]+=e-j+1;
                temp[k++]=arr[i++];
            }
        }
        
        while(i<=mid)
        {
            temp[k++]=arr[i++];
        }
        
        while(j<=e)
        {
            temp[k++]=arr[j++];
        }
        
        for(int i=0;i<temp.size();i++)
        {
            arr[s+i]=temp[i];
        }
    }
    
    void mergeSort(int s,int e,vector<pair<int,int>>&arr,vector<int>&result)
    {
        if(s>=e)return;
        int mid=(s+e)/2;
        mergeSort(s,mid,arr,result);
        mergeSort(mid+1,e,arr,result);
        merge(s,mid,e,arr,result);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }
        vector<int>result(n,0);
        mergeSort(0,n-1,arr,result);
        return result;
    }
};