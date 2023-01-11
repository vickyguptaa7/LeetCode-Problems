class Solution {
public:
    
    bool isValid(int num,vector<vector<int>>&statements)
    {
        for(int i=0;i<statements.size();i++)
        {
            if(num&(1<<i))
            {
                for(int j=0;j<statements[i].size();j++)
                {
                    if(statements[i][j]==2)
                        continue;
                    if(statements[i][j]==0&&(num&(1<<j)))
                        return false;
                    if(statements[i][j]==1&&!(num&(1<<j)))
                        return false;
                }
            }
        }
        return true;
    }
    
    int maximumGood(vector<vector<int>>& statements) {
        int size=statements.size();
        int total=(1<<size);
        int maxGood=0;
        for(int i=0;i<total;i++)
        {
            if(isValid(i,statements))
            {
                maxGood=max(maxGood,__builtin_popcount(i));
            }
        }
        return maxGood;
    }
};