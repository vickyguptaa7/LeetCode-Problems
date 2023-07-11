class Solution
{
    vector<string> ones = { "",
        " One",
        " Two",
        " Three",
        " Four",
        " Five",
        " Six",
        " Seven",
        " Eight",
        " Nine",
        " Ten",
        " Eleven",
        " Twelve",
        " Thirteen",
        " Fourteen",
        " Fifteen",
        " Sixteen",
        " Seventeen",
        " Eighteen",
        " Nineteen" };
    vector<string> tens = { "",
        " Ten",
        " Twenty",
        " Thirty",
        " Forty",
        " Fifty",
        " Sixty",
        " Seventy",
        " Eighty",
        " Ninety" };
    vector<string> thousands = { "",
        " Thousand",
        " Million",
        " Billion" };
    
    string helper(int num)
    {
        if(num<20)
        {
            return ones[num];
        }
        else if(num<100)
        {
            return tens[num/10]+helper(num%10);
        }
        else if(num<1000)
        {
            return helper(num/100)+" Hundred"+helper(num%100);
        }
        for(int i=3;i>=0;i--)
        {
            if(num>=pow(1000,i))
            {
                return helper(num / pow(1000, i)) + thousands[i] + helper(num % (int)pow(1000, i));
            }
        }
        return "";
    }
    public: string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        return helper(num).substr(1);
    }
};