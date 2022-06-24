class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pque(target.begin(),target.end());
        long long targetSum=accumulate(target.begin(),target.end(),0ll);
        
        while(!pque.empty()&&pque.top()!=1)
        {
            int num=pque.top();
            pque.pop();
            targetSum-=num;
            if(targetSum==1)return true;
            
            if(num<=targetSum||targetSum==0||num%targetSum==0)return false;
            pque.push(num%targetSum);
            targetSum+=num%targetSum;
        }
        return true;
    }
};