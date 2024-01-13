class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int>dp(1e4+5,-1);
        queue<int>que;
        que.push(x);
        dp[x]=0;
        int oper=0;
        while(!que.empty())
        {

            int size=que.size();
            while(size--)
            {
            int curr=que.front();
            que.pop();
            if(curr==y)
                return oper;
            if(curr%11==0&&dp[curr/11]==-1)
            {
                dp[curr/11]=oper;
                que.push(curr/11);
            }
            if(curr%5==0&&dp[curr/5]==-1)
            {
                dp[curr/5]=oper;
                que.push(curr/5);
            }
            if(curr+1<1e4+5&&dp[curr+1]==-1)
            {
                dp[curr+1]=oper;
                que.push(curr+1);
            }
            if(curr-1>=0&&dp[curr-1]==-1)
            {
                dp[curr-1]=oper;
                que.push(curr-1);
            }
            }
            oper++;       
        }
        return abs(x-y);
    }
};