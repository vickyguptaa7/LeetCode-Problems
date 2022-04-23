class Solution {
public:
    int factorTwo(int num)
    {
        int cnt=0;
        while(num>0&&num%2==0)
        {
            cnt++;
            num/=2;
        }
        return cnt;
    }
    int factorFive(int num)
    {
        int cnt=0;
        while(num>0&&num%5==0)
        {
            cnt++;
            num/=5;
        }
        return cnt;
    }
    vector<vector<pair<int,int>>>upInitialize(vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>up(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<m;i++)
        {
            int twoCnt=0,fiveCnt=0;
            for(int j=n-1;j>=0;j--)
            {
                twoCnt+=factorTwo(grid[j][i]);
                fiveCnt+=factorFive(grid[j][i]);
                up[j][i]={twoCnt,fiveCnt};
            }
        }
        return up;
    }
    vector<vector<pair<int,int>>>downInitialize(vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>down(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<m;i++)
        {
            int twoCnt=0,fiveCnt=0;
            for(int j=0;j<n;j++)
            {
                twoCnt+=factorTwo(grid[j][i]);
                fiveCnt+=factorFive(grid[j][i]);
                down[j][i]={twoCnt,fiveCnt};
            }
        }
        return down;
    }
    vector<vector<pair<int,int>>>leftInitialize(vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>left(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<n;i++)
        {
            int twoCnt=0,fiveCnt=0;
            for(int j=0;j<m;j++)
            {
                twoCnt+=factorTwo(grid[i][j]);
                fiveCnt+=factorFive(grid[i][j]);
                left[i][j]={twoCnt,fiveCnt};
            }
        }
        return left;
    }
    vector<vector<pair<int,int>>>rightInitialize(vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>right(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<n;i++)
        {
            int twoCnt=0,fiveCnt=0;
            for(int j=m-1;j>=0;j--)
            {
                twoCnt+=factorTwo(grid[i][j]);
                fiveCnt+=factorFive(grid[i][j]);
                right[i][j]={twoCnt,fiveCnt};
            }
        }
        return right;
    }
    void show(vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>up=upInitialize(grid);
        vector<vector<pair<int,int>>>down=downInitialize(grid);
        vector<vector<pair<int,int>>>left=leftInitialize(grid);
        vector<vector<pair<int,int>>>right=rightInitialize(grid);
        
//         show(up);
//         show(left);
//         show(right);
//         show(down);
        
        int Max=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int gct=factorTwo(grid[i][j]);
                int gcf=factorFive(grid[i][j]);
                int twoCnt=down[i][j].first+left[i][j].first-gct;
                int fiveCnt=down[i][j].second+left[i][j].second-gcf;
                Max=max(Max,min(twoCnt,fiveCnt));
                
                twoCnt=down[i][j].first+right[i][j].first-gct;
                fiveCnt=down[i][j].second+right[i][j].second-gcf;
                Max=max(Max,min(twoCnt,fiveCnt));
                
                twoCnt=left[i][j].first+up[i][j].first-gct;
                fiveCnt=left[i][j].second+up[i][j].second-gcf;
                Max=max(Max,min(twoCnt,fiveCnt));
                
                twoCnt=right[i][j].first+up[i][j].first-gct;
                fiveCnt=right[i][j].second+up[i][j].second-gcf;
                Max=max(Max,min(twoCnt,fiveCnt));
            }
        }
        
        return Max;
        
    }
};