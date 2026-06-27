class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,map<int,int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            int count=0, num=nums[i];
            while(num!=1&&int(sqrt(num))*int(sqrt(num))==num)
            {
                num = sqrt(num);
                count++;
            }
            mp[num][count]++;
        }
        int mx=1;
        for(auto m:mp)
        {
            for(int j=0;j<32;j++)
            {
            int temp=0;

            for(int i=j;i<32;i++)
            {
                if(m.second.count(i))
                {
                    temp=i-j;
                    if(m.second[i]==1)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            mx=max(mx,temp*2+1);
            }
        }
        return max(mx,mp[1][0]%2?mp[1][0]:mp[1][0]-1);
    }
};