class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int head=-1,tail=0,cost=0;
        int len=0,n=s.size();
        while(head<n)
        {
            while(head+1<s.size()&&(abs(s[head+1]-t[head+1])+cost)<=maxCost)
            {
                cost+=abs(s[head+1]-t[head+1]);
                head++;
            }
            len=max(len,head-tail+1);
            if(head<tail)
            {
                head=tail;
                tail++;
            }
            else
            {
                cost-=abs(s[tail]-t[tail]);
                tail++;
            }
        }
        return len;
    }
};