class Solution
{
    public:
        int rev(int x)
        {
            int res = 0;
            while (x > 0)
            {
                res = (x % 10) + res * 10;
                x /= 10;
            }
            return res;
        }
    int digitCount(int num)
    {
        int cntr = 0;
        while (num)
        {
            num /= 10;
            cntr++;
        }
        return cntr - 1;
    }
    int reverse(int x)
    {
        if (x == 0) return x;
        if (x == -2147483648) return false;

        int sign = (x < 0) ? -1 : 1;
        x=abs(x);

        int y2 = 2147483647;
        int y1 = x;
        int digits = digitCount(x);

        if (digits == 9)
        {
            int power = pow(10, 9);
            for (int i = 0; i < 10; i++)
            {
                int rem1 = (y1) % 10;
                int rem2 = (y2 / power) % 10;
                if (rem1 > rem2) return 0;
                else if (rem1 < rem2) break;
                power /= 10;
                y1 /= 10;
            }
        }
        return sign* rev(x);
    }
};