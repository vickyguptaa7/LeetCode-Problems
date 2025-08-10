class Solution { 

    public boolean reorderedPowerOf2(int n) {
        int[] freq= new int [10];
        while(n>0)
        {
            int digit=n%10;
            freq[digit]++;
            n/=10;
        }
        for(int i=0;i<31;i++)
        {
            int num=(1<<i);
            int[] freq1=new int[10];
            while(num>0)
            {
                int digit=num%10;
                freq1[digit]++;
                num/=10;
            }
            boolean isCorrect=true;
            for(int j=0;j<10;j++)
            {
                if(freq[j]!=freq1[j])
                {
                    isCorrect=false;
                    break;
                }

            }
            if(isCorrect)
                return true;
        }
        return false;
    }
}