bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[1]!=b[1])
    {
        return a[1]<b[1];
    }
    else 
    {
        return a[0]<b[0];
    }
    
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycomp);
        stack<vector<int>>stack;
        stack.push(intervals[0]);
        int n=intervals.size();
        int counter=0;
        for(int i=1;i<n;i++)
        {
            vector<int>intr=stack.top();
            if(intr[1]>intervals[i][0])
            {
                counter++;
            }
            else
            {
                stack.push(intervals[i]);
            }
        }
        return counter;
    }
};