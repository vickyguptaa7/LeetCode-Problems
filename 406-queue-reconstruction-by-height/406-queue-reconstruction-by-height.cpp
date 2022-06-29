bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[0]!=b[0])
    {
        return a[0]>b[0];
    }
    return a[1]<b[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),mycomp);
        vector<vector<int>>result(people.size(),vector<int>(2,-1));
        
        for(int i=0;i<people.size();i++)
        {
            int idx=people[i][1];

            if(result[idx][0]!=-1)
            {
                int target=-1;
                for(int j=idx;j<people.size();j++)
                {
                    if(result[j][0]==-1)
                    {
                        target=j;
                        break;
                    }
                }
                for(int j=target-1;j>=idx;j--)
                {
                    result[j+1][0]=result[j][0];
                    result[j+1][1]=result[j][1];
                }
            }
            
            result[idx][0]=people[i][0];
            result[idx][1]=people[i][1];
        }
        
        return result;
    }
};