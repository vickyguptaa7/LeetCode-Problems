class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count=0,n=arr.size(),mx=0,ans=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                count++;
            }
            else
            {
                if(mx<count)
                {
                    mx=count;
                    ans=arr[i-1];
                }
                count=1;
            }
        }
        if(count>=mx)
            return arr.back();
        return ans;
    }
};