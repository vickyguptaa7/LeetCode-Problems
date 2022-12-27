class Solution {
public:
    int smallestValue(int n) {
        bool isNotPrime=false;
        while(!isNotPrime)
        {
            int temp=0,num=n;
            for(int i=2;i*i<=n;i++)
            {
                while(n%i==0)
                {
                    temp+=i;
                    n/=i;
                }
            }
            if(temp==0)
            {
                isNotPrime=true;
            }
            else if(n!=1)
            {
                temp+=n;
                n=temp;
            }
            else
            {
                n=temp;
            }
            if(temp==num)
            {
                return num;
            }
        }
        return n;
    }
};