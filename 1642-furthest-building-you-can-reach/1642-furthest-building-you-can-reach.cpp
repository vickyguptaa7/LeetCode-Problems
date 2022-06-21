class Solution {
public:
    
    bool isValid(vector<pair<int,int>>&work,int bricks,int ladders,int farBuilding)
    {
        vector<int>dummy;
        for(int i=0;i<work.size();i++)
        {
            if(work[i].second>farBuilding)break;
            dummy.push_back(work[i].first);
        }
        
        sort(dummy.begin(),dummy.end(),greater<int>());
        
        for(int i=0;i<dummy.size();i++)
        {
            if(ladders>i)continue;
            bricks-=dummy[i];
        }
        if(bricks<0)return false;
        return true;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int Min=0,Max=n-1,ans=0;
        
        vector<pair<int,int>>work;
        for(int i=1;i<n;i++)
        {
            if(heights[i]>heights[i-1])
            {
                work.push_back({heights[i]-heights[i-1],i});
            }
        }
        
        while(Min<=Max)
        {
            int mid=Min+(Max-Min)/2;
            if(isValid(work,bricks,ladders,mid))
            {
                ans=mid;
                Min=mid+1;
            }
            else
            {
                Max=mid-1;
            }
        }
        return ans;
    }
};