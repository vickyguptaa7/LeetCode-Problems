class Solution {
public:
    int maxProduct(int n) {
        int m1=0, m2=0;
        while(n)
        {
            int num = n%10;
            if(num>m1)
            {
                m2=m1;
                m1=num;
            }
            else 
            {
                m2=max(m2,num);
            }
            n/=10;
        }
        return m1*m2;
    }
};