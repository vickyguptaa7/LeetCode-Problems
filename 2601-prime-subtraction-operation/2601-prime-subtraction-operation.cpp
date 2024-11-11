class Solution {
public:
    
    vector<int> getPrime(int n)
    {
        vector<int>prime(n+5,1);
        prime[1]=1;
        prime[0]=1;
        for(int i=2;i<prime.size();i++)
        {
            for(int j=i;j<prime.size();j+=i)
            {
                if(prime[j]==1)
                {
                    prime[j]=i;
                }
                else
                {
                    prime[j]=min(i,prime[j]);
                }
            }
        }
        vector<int>ans;
        for(int i=2;i<prime.size();i++)
        {
            if(i==prime[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        vector<int>prime=getPrime(1000);
        int prev=0;
        for(int i=0;i<nums.size();i++)
        {
            int sub=nums[i]-prev;
            int indx=lower_bound(prime.begin(),prime.end(),sub)-prime.begin();

            if(indx==prime.size()||prime[indx]>=sub)
                indx--;
            
            if(indx>=0)
                nums[i]-=prime[indx];

            if(prev>=nums[i])
                return false;
            prev=nums[i];

        }

        return true;
    }
};