class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        int curr=1,prev=0;
        for(int i=2;i<=n;i++)
        {
            int temp=prev;
            prev=curr;
            curr=curr+temp;
        }
        return curr;
    }
};