class Solution {
public:
    
    bool isValid(vector<int>&position,int m,int dist)
    {
        int prev=0;
        m--;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-position[prev]>=dist)
            {
                m--;
                prev=i;
            }
        }
        return m<=0;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int low=1,high=1e9+5,ans=0;
        sort(position.begin(),position.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(position,m,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};