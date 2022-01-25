class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>list;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            if(i>0&&arr[i-1]==arr[i])continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(arr[i]+arr[j]+arr[k]==0)
                {
                    list.push_back({arr[i],arr[j],arr[k]});
                    while(j<k&&arr[j]==arr[j+1])j++;
                    while(j<k&&arr[k]==arr[k-1])k--;
                    j++;
                    k--;
                }
                else if(arr[i]+arr[j]+arr[k]>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return list;
    }
};