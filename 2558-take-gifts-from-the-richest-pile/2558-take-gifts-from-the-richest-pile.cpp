class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pque(gifts.begin(),gifts.end());
        while(!pque.empty()&&k--)
        {
            int curr=pque.top();
            pque.pop();
            if(int(sqrt(curr))!=0)
            {
                pque.push(sqrt(curr));
            }
        }
        long long ans=0;
        while(!pque.empty())
        {
            ans+=pque.top();
            pque.pop();
        }
        return ans;
    }
};