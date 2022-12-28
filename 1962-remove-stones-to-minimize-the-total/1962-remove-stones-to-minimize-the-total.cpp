class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pque(piles.begin(),piles.end());
        while(k--)
        {
            int curr=pque.top();
            pque.pop();
            curr-=(curr/2);
            pque.push(curr);
        }
        int total=0;
        while(!pque.empty())
        {
            total+=pque.top();
            pque.pop();
        }
        return total;
    }
};