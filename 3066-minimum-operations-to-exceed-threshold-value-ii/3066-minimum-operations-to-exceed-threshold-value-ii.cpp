typedef long long ll;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pque(nums.begin(),nums.end());
        int oper=0;
        while(pque.size()>1&&pque.top()<k)
        {
            ll num1=pque.top();
            pque.pop();
            ll num2=pque.top();
            pque.pop();
            pque.push(num1*2+num2);
            oper++;
        }
        return oper;
    }
};