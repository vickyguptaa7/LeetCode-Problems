class Solution {
    private double pow(double x,int n)
    {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        double val = pow(x,n/2);
        return (n%2)==0?val*val:val*val*x;
    }
    public double myPow(double x, int n) {
        if(n<0)
            return 1/pow(x,-n);
        return pow(x,n);
    }
}