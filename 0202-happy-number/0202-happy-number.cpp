class Solution {
public:
    bool isHappy(int n) {
        set<int>oset;
        oset.insert(n);
        while(n!=1)
        {
            int temp=n,sum=0;
            while(temp)
            {
                sum+=(temp%10)*(temp%10);
                temp/=10;
            }
            if(oset.count(sum))
                return false;
            oset.insert(sum);
            n=sum;
        }
        return true;
    }
};