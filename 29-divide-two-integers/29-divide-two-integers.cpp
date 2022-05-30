class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            long long res = 0,divid=dividend,divis=divisor;
            int sign = 1;
            if (divid < 0)
            {
                divid = abs(divid);
                sign *= -1;
            }
            if (divis < 0)
            {
                divis = abs(divis);
                sign *= -1;
            }

            for (int i = 31;i>=0;i--)
            {
                long long div=(1ll<<i);
                if(div*divis<=divid-res*divis)
                {
                    res+=div;
                }
            }
            res*=sign;
            if(res> INT_MAX )return INT_MAX;
            if(res<INT_MIN)return INT_MIN;
            return res;
        }
};