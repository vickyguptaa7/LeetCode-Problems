class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>arr.size())
            return *max_element(arr.begin(),arr.end());
        queue<int>que;
        for(auto x:arr)que.push(x);
        int curr=que.front();
        que.pop();
        int res=-1;
        while(res<k)
        {
            res=res==-1?0:1;
            while(res<k&&curr>que.front())
            {
                que.push(que.front());
                que.pop();
                res++;
            }
            if(res<k)
            {
                que.push(curr);
                curr=que.front();
                que.pop();
            }
        }
        return curr;
    }
};