bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[0]!=b[0])
    {
        return a[0]<b[0];
    }
    else 
    {
        return a[1]<b[1];
    }
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycomp);
        stack<vector<int>>stack_interval;
        stack_interval.push(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            vector<int>interval=stack_interval.top();
            stack_interval.pop();
            if(interval[1]>=intervals[i][0])
            {
                interval[1]=max(interval[1],intervals[i][1]);
                stack_interval.push(interval);
            }
            else
            {
                stack_interval.push(interval);
                stack_interval.push(intervals[i]);
            }
        }
        vector<vector<int>>answer;
        while(!stack_interval.empty())
        {
            answer.push_back(stack_interval.top());
            stack_interval.pop();
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};