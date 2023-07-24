class Solution {
public:
    
    double helper(double x,int n)
    {        
        if(n==0)
            return 1;

        double val=helper(x,n/2);

        if(n&1)
            return x*val*val;
        
        return val*val;
    }
    
    double myPow(double x, int n) {
        if(n<0)
            return helper(1/x,abs(n));
        return helper(x,n);
    }
};