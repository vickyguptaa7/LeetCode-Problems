class Solution {
public:
    vector<int>Prime()
    {
        vector<int>isPrime(32,0);
        for(int i=2;i<32;i++)
        {
            bool isTrue=1;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    isTrue=0;
                    break;
                }
            }
            if(isTrue)
              isPrime[i]=1;
        }
        for(auto x:isPrime)cout<<x<<" ";
        cout<<"\n";
        return isPrime;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int>isPrime=Prime();
        int count=0;
        for(int i=left;i<=right;i++)
        {
            int bitCount=0;
            int temp=i;
            while(temp)
            {
                if(temp%2==1)bitCount++;
                temp/=2;
            }
            if(isPrime[bitCount])count++;
        }
        return count;
    }
};