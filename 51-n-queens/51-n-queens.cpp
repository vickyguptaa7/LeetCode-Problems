class Solution {
public:
    
    bool isValid(int x,int y,vector<string> ans)
    {
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i][y]=='Q')return false;
        }
        
        int r=x,c=y;
        while(r>=0&&c>=0)
        {
            if(ans[r][c]=='Q')return false;
            r--;
            c--;
        }
        r=x,c=y;
        while(r>=0&&c<ans.size())
        {
            if(ans[r][c]=='Q')return false;
            r--;
            c++;
        }
        return true;
    }
    
    void helper(int x,vector<string>ans,vector<vector<string>>&result)
    {
        if(x==ans.size())
        {
            result.push_back(ans);
            return;
        }
        
        for(int i=0;i<ans.size();i++)
        {
            if(isValid(x,i,ans))
            {
                ans[x][i]='Q';
                helper(x+1,ans,result);
                ans[x][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            string row;
            for(int j=0;j<n;j++)
            {
                row+=".";
            }
            ans.push_back(row);
        }
        helper(0,ans,result);
        return result;
    }
};