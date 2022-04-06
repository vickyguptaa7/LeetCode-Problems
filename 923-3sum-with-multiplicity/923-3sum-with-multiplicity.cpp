class Solution {
public:
    
    long long ncr(int n,int r)
    {
        long long c=1;
        for(int i=n;i>n-r;i--)
        {
            c*=i;
        }
        for(int i=1;i<=r;i++)
        {
            c/=i;
        }
        return c;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        
        map<int,int>freq;
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        long long answer=0,mod=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            if(i>0&&arr[i]==arr[i-1])continue;
            int low=i+1,high=arr.size()-1;
            while(low<high)
            {
                int total=arr[i]+arr[low]+arr[high];
                if(total==target)
                {
                    if(arr[i]==arr[low]&&arr[i]==arr[high])
                    {
                        answer+=ncr(freq[arr[i]],3);
                    }
                    else if(arr[i]==arr[low])
                    {
                        answer+=(ncr(freq[arr[i]],2))*freq[arr[high]];
                    }
                    else if(arr[low]==arr[high])
                    {
                        answer+=(ncr(freq[arr[low]],2))*freq[arr[i]];
                    }
                    else
                    {
                        answer+=freq[arr[i]]*freq[arr[low]]*freq[arr[high]];
                    }
                    answer%=mod;
                    low++;
                    high--;
                    while(low<arr.size()&&arr[low]==arr[low-1])low++;
                    while(high>=0&&arr[high]==arr[high+1])high--;
                }
                else if(total>target)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return answer;
    }
};