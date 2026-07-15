class Solution {
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,abs(a-b));
    }
public:
    int gcdOfOddEvenSums(int n) {
        int odd_sum = n*(1+(2*n-1))/2;
        int even_sum = n*(n+1);
        cout<<even_sum<<" "<<odd_sum;
        return gcd(even_sum,odd_sum);
    }
};