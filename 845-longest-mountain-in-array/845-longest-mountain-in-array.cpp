class Solution {
public:
    int longestMountain(vector<int>& arr) {
        vector<int>diff;
        for(int i=1;i<arr.size();i++)
        {
            diff.push_back(arr[i]-arr[i-1]);
        }
        int long_mount=0,mlength=0,isPositive=true;
        for(int i=0;i<diff.size();i++)
        {
            if(diff[i]>0)
            {
                if(isPositive)
                {
                    mlength++;
                }
                else
                {
                    if(!isPositive&&mlength>1)
                    {
                        long_mount=max(mlength,long_mount);
                    }
                    mlength=1;
                    isPositive=true;
                }
            }
            else if(diff[i]<0)
            {
                if(!isPositive)
                {
                    mlength++;
                    long_mount=max(mlength,long_mount);
                }
                else
                {
                    if(mlength>0)
                    {
                        isPositive=false;
                        mlength++;
                        long_mount=max(mlength,long_mount);
                    }
                    else
                    {
                        mlength=0;
                        isPositive=true;
                    }
                }
            }
            else
            {
                if(!isPositive&&mlength>1)
                {
                    long_mount=max(mlength,long_mount);
                }
                mlength=0;
                isPositive=true;
            }
        }
        return long_mount==0?0:long_mount+1;
    }
};