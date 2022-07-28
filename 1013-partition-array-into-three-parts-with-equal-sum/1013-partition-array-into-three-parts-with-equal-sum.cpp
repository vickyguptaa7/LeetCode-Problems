class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long sum=accumulate(arr.begin(),arr.end(),0ll);
        if(sum%3!=0)return false;
        sum/=3;
        long long s=0,cnt=0,n=arr.size();
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            if(s==sum)
            {
                cnt++;
                s=0;
            }
        }
        return cnt>=3;
    }
};