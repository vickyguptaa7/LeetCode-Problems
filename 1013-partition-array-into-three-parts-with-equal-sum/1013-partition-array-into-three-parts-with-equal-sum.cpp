class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%3!=0)return false;
        int s1=sum/3;
        
        int s=0;
        int check=1;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            if(s==s1*check)
            {
                check++;
            }
        }
        if(check>3)return true;
        else return false;
    }
};