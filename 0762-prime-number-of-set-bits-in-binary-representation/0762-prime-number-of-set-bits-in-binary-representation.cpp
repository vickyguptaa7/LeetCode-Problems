class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> isPrime(32);
        isPrime[0] = false;
        isPrime[1] = false;
        isPrime[2] = true;
        isPrime[3] = true;
        isPrime[4] = false;
        isPrime[5] = true;
        isPrime[6] = false;
        isPrime[7] = true;
        isPrime[8] = false;
        isPrime[9] = false;
        isPrime[10] = false;
        isPrime[11] = true;
        isPrime[12] = false;
        isPrime[13] = true;
        isPrime[14] = false;
        isPrime[15] = false;
        isPrime[16] = false;
        isPrime[17] = true;
        isPrime[18] = false;
        isPrime[19] = true;
        isPrime[20] = false;
        isPrime[21] = false;
        isPrime[22] = false;
        isPrime[23] = true;
        isPrime[24] = false;
        isPrime[25] = false;
        isPrime[26] = false;
        isPrime[27] = false;
        isPrime[28] = false;
        isPrime[29] = true;
        isPrime[30] = false;
        isPrime[31] = false;
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int num=i,cnt=0;
            while(num)
            {
                cnt+=num&1;
                num/=2;
            }
            ans += isPrime[cnt];
        }
        return ans;
    }
};