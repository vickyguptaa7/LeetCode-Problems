class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>distinctSum;
        int n=grid.size(),m=grid[0].size();
        int size=(min(n,m)-1)/2;
        for(int i=0;i<=size;i++)
        {
            for(int j=i;j<n-i;j++)
            {
                for(int k=0;k<m-2*i;k++)
                {
                    int x=j,y=k;
                    int temp=i;
                    int sum=0;
                    if(i==0)
                        sum+=grid[x][y];
                    while(temp)
                    {
                        x--;
                        y++;
                        sum+=grid[x][y];
                        temp--;
                    }
                    while(temp<i)
                    {
                        x++;
                        y++;
                        sum+=grid[x][y];
                        temp++;
                    }
                    while(temp)
                    {
                        x++;
                        y--;
                        sum+=grid[x][y];
                        temp--;
                    }
                    while(temp<i)
                    {
                        x--;
                        y--;
                        sum+=grid[x][y];
                        temp++; 
                    }
                    distinctSum.insert(sum);
                }
            }
        }
        vector<int>result;
        int cntr=3;
        while(!distinctSum.empty()&&cntr--)
        {
            result.push_back(*distinctSum.rbegin());
            distinctSum.erase(result.back());
        }
        return result;
    }
};