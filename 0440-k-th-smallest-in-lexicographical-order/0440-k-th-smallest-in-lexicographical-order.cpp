typedef long long ll;
class Solution {
public:
    
    long long nodesCount(ll n,ll curr)
    {
        ll total=0,next=curr+1;
        while(curr<=n)
        {
            total+=min(n-curr+1,next-curr);
            curr*=10;
            next*=10;
        }
        return total;
    }
    
    int findKthNumber(int n, int k) {
        ll curr=1;
        k--;
        while(k>0)
        {
            int node=nodesCount(n,curr);
            if(k>=node)
            {
                curr+=1;
                k-=node;
            }
            else
            {
                curr*=10;
                k--;
            }
        }
        return curr;
    }
    
};