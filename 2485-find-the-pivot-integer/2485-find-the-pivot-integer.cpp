class Solution {
public:
    int pivotInteger(int n) {
        int psum=0,sum=n*(n+1)/2;
        for(int i=1;i<=n;i++)
        {
            psum+=i;
            if(psum==sum)return i;
            sum-=i;
        }
        return -1;
    }
};