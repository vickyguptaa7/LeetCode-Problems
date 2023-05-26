class Solution {
public:
    
    int helper(int strt,string snum,int num,int sum)
    {
        if(sum>num)
            return false;
        if(strt==snum.size())
            return num==sum;
        int temp=0;
        for(int i=strt;i<snum.size();i++)
        {
            temp=temp*10+(snum[i]-'0');
            if(helper(i+1,snum,num,sum+temp))
                return true;
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(helper(0,to_string(i*i),i,0))
            {
                ans+=i*i;
            }
        }
        return ans;
    }
};