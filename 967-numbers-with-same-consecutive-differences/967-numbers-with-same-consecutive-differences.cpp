class Solution {
public:
    void helper(int s,string num,int n,int k,vector<int>&ans)
    {
        if(s==n)
        {
            ans.push_back(stoi(num));
            return;
        }
        for(int i=0;i<=9;i++)
        {
            if(s!=0)
            {
                char prev=num.back();
                char curr=i+'0';
                if(abs(curr-prev)!=k)continue;
                helper(s+1,num+curr,n,k,ans);
            }
            else 
            {
                if(i==0)continue;
                char curr=i+'0';
                helper(s+1,num+curr,n,k,ans);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        helper(0,"",n,k,ans);
        return ans;
    }
};