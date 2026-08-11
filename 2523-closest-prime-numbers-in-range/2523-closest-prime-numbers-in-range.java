class Solution {
    public int[] closestPrimes(int left, int right) {
        int limit = 1000001;
        int[] is_prime = new int[limit];
        for (int i = 2; i < limit; i++)
            is_prime[i] = 1;

        for (int i = 2; i < limit; i++) {
            for (long j = (long) i * i; j < limit; j += i) {
                is_prime[(int)j] = 0;
            }
        }

        int prev=-1;
        int[] res = new int[]{-1,-1};
        for (int i = left; i <= right; i++) {
            if(is_prime[i]==0)continue;
            if(prev == -1)
            {
                prev = i;
            }
            else 
            {
                if(res[0]==-1||i-prev<res[1]-res[0])
                {
                    res[0]=prev;
                    res[1]=i;
                }
                prev = i;
            }
        }

        return res;
    }
}