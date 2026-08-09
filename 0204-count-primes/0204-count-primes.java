class Solution {
    public int countPrimes(int n) {
        int[] prime = new int[n+2];
        prime[0]=1;
        prime[1]=1;
        for(int i=2;i<n;i++)
        {
            for(long j=(long)i*i;j<n;j+=i)
            {
                prime[(int)j]=1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=prime[i]==0?1:0;
        }
        return count;
    }
}