class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1)return 0;
        int noOfTest=minutesToTest/minutesToDie+1;
        int ans=noOfTest;
        int cnt=1;
        while(buckets>ans)
        {
            cnt++;
            ans*=noOfTest;
        }
        return cnt;
    }
};