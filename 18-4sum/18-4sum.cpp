class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&arr[i]==arr[i-1])continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&arr[j]==arr[j-1])continue;
            
                int low=j+1,high=n-1;
                while(low<high)
                {
                    long long sum=arr[i]+arr[j]+(long long)arr[low]+arr[high];
                    if(sum==target)
                    {
                        res.push_back({arr[i],arr[j],arr[low],arr[high]});
                        low++;
                        high--;
                        while(low<n&&arr[low]==arr[low-1])low++;
                        while(high>low&&arr[high]==arr[high+1])high--;
                    }
                    else if(sum>target)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                        
                }
            }
        }
        return res;
    }
};