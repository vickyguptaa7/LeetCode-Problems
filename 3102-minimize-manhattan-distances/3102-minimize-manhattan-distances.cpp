class Solution {
public:
    
    vector<int> findMaxDistance(vector<vector<int>>&points,int exc)
    {
        pair<int,int> maxSum={-1,-1e9},minSum={-1,1e9},maxDiff={-1,-1e9},minDiff={-1,1e9};
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            if(exc==i)continue;
            int sum=points[i][0]+points[i][1];
            int diff=points[i][0]-points[i][1];
            
            if(sum>maxSum.second)
            {
                maxSum={i,sum};
            }
            if(sum<minSum.second)
            {
                minSum={i,sum};
            }
            if(diff>maxDiff.second)
            {
                maxDiff={i,diff};
            }
            if(diff<minDiff.second)
            {
                minDiff={i,diff};
            }
        }
        int resSum=maxSum.second-minSum.second;
        int resDiff=maxDiff.second-minDiff.second;
        if(resSum>resDiff)
        {
            return {resSum,minSum.first,maxSum.first};
        }
        return {resDiff,minDiff.first,maxDiff.first};
    }
    
    int minimumDistance(vector<vector<int>>& points) {
        vector<int>res=findMaxDistance(points,-1);
        return min(findMaxDistance(points,res[1]),findMaxDistance(points,res[2]))[0];
    }
};