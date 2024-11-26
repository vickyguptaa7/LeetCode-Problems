bool comp(vector<int>& a,vector<int>& b)
{
    if(a[0]!=b[0])
        return a[0]<b[0];
    return a[1]>b[1];
}

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end(),comp);
        int qit=0,not_removed=0;
        priority_queue<int>candidate;
        priority_queue<int,vector<int>,greater<int>>choosen;
        for(int i=0;i<nums.size();i++)
        {
            while(qit<queries.size()&&queries[qit][0]==i)
            {
                candidate.push(queries[qit][1]);
                qit++;
            }
            nums[i]-=choosen.size();
            while(nums[i]>0&&!candidate.empty()&&candidate.top()>=i)
            {
                not_removed++;
                choosen.push(candidate.top());
                candidate.pop();
                nums[i]--;
            }
            if(nums[i]>0)
                return -1;
            while(!choosen.empty()&&choosen.top()==i)
            {
                choosen.pop();
            }
        }
        return queries.size()-not_removed;
    }
};