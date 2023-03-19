class Compare {
    public:
       bool operator()(pair<int,int>& a, pair<int,int>&b){
           return (a.first>b.first)||(a.first==b.first&&a.second>b.second);
      }
};

class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        Compare>pque;
        vector<int>visited(nums.size(),false);
        for(int i=0;i<nums.size();i++)pque.push({nums[i],i});
        long long score=0;
        while(!pque.empty())
        {
            auto curr=pque.top();
            pque.pop();
            if(visited[curr.second])
            {
                continue;
            }
            score+=curr.first;
            if(curr.second-1>=0)visited[curr.second-1]=true;
            if(curr.second+1<nums.size())visited[curr.second+1]=true;
        }
        return score;
    }
};