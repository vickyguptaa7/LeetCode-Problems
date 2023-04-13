class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>stk;
        int iter=0;
        for(int i=0;i<pushed.size();i++)
        {
            stk.push(pushed[i]);
            while(iter<pushed.size()&&!stk.empty()&&stk.top()==popped[iter])
                stk.pop(),iter++;
        }
        return iter==popped.size();
    }
};