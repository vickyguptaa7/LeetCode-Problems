class Solution {
public:

    bool isZero(int n)
    {
        int has=false;
        while(n)
        {
            if(n%10==0)
                has=true;
            n/=10;
        }
        return has;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++)
        {
            if(!isZero(i)&&!isZero(n-i))
                return {i,n-i};
        }
        return {n-1,1};
    }
};