class Solution {
public:
    int countSpecialNumbers(int n) {
        if(n<10)return n;
        vector<int>dp(11,0);
        int ans=0;
        for(int i=1;i<=10;i++)
        {
            int mult=9,itr=9;
            for(int j=i;j>1;j--)
            {
                mult*=itr;
                itr--;
            }
            dp[i]=mult;
        }
        int dig=log10(n);
        for(int i=0;i<=dig;i++)ans+=dp[i];
        // cout<<ans<<"\n";
        string num=to_string(n);
        
        int size=(int)num.size()-1;
        set<int>oset={1,2,3,4,5,6,7,8,9,0},oset1;
    
        for(int i=0;i<num.size();i++)
        {
            if(num[i]-'1'>=0)
            {
                int mult=0;
                for(int k=0;k<=num[i]-'1';k++)
                {
                    if(oset.count(k))mult++;
                }
                if(i==0)mult--;
                // cout<<i<<"\n"<<mult<<"\n";
                int cnt=oset.size()-1;
                for(int i=1;i<=size;i++)
                {
                    // cout<<cnt<<" ";
                    mult*=(cnt);
                    cnt--;
                }
                // cout<<"\n";
                // cout<<mult<<"\n";
                ans+=mult;
            }
            size--;
            oset.erase(num[i]-'0');
            if(!oset1.count(num[i]))
            {
                oset1.insert(num[i]);
            }
            else break;
            if(i+1==num.size())ans++;
        }
        return ans;
    }
};