class Solution {
public:
    
    bool helper(int s,vector<int>&match,int arr[],int sum)
    {
        if(s==match.size())
        {
            for(int i=0;i<4;i++)
            {
                if(arr[i]!=sum)
                    return 0;
            }
            return 1;
        }
        
        
        bool isWay=false;
        for(int i=0;i<4;i++)
        {
            if(arr[i]+match[s]<=sum)
            {
                arr[i]+=match[s];
                isWay=(isWay|helper(s+1,match,arr,sum));
                if(isWay)return true;
                arr[i]-=match[s];
            }
        }
        return isWay;
    }
    bool makesquare(vector<int>& matchsticks) {
        long long sum=accumulate(matchsticks.begin(),matchsticks.end(),0ll);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        if(sum%4!=0)
            return false;
        
        sum/=4;
        
        int arr[4]={0};
        return helper(0,matchsticks,arr,sum);
    }
};