class Solution {
public:
    long long smallestNumber(long long num) {
        bool isNeg=(num<0)?1:0;
        num=abs(num);
        vector<int>digits;
        while(num)
        {
            digits.push_back(num%10);
            num/=10;
        }
        if(digits.size()==0)
        {
            return 0;
        }
        if(isNeg)
        {
            sort(digits.begin(),digits.end(),greater<int>());
            long long result=0;
            for(auto x:digits)
            {
                result=result*10+x;
            }
            return -result;
        }
        else
        {
            sort(digits.begin(),digits.end());
            int zeroCnt=0;
            for(int i=0;i<digits.size();i++)
            {
                if(digits[i]==0)
                {
                    zeroCnt++;
                }
                else
                {
                    break;
                }
            }
            long long result=digits[zeroCnt];
            for(int i=0;i<zeroCnt;i++)
            {
                result*=10;
            }
            for(int i=zeroCnt+1;i<digits.size();i++)
            {
                result=result*10+digits[i];
            }
            return result;
        }
            
    }
};