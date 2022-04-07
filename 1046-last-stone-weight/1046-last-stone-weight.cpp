class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pque(stones.begin(),stones.end());
        while(pque.size()>1)
        {
            int s1=pque.top();
            pque.pop();
            int s2=pque.top();
            pque.pop();
            if(s1!=s2)
            {
                pque.push(s1-s2);
            }
        }
        return (pque.empty())?0:pque.top();
    }
};