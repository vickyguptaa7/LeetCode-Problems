class Solution {
public:
    
    int helper(int n1,int n2)
    {
        int cnt=1;
        while(n1>1||n2>1)
        {
            if(n1==n2)
            {
                return cnt;
            }
            else if(n1>n2)
            {
                n1/=2;
            }
            else 
            {
                n2/=2;
            }
            cnt++;
        }
        return cnt;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>result;
        for(auto x:queries)
        {
            result.push_back(helper(x[0],x[1]));
        }
        return result;
    }
};