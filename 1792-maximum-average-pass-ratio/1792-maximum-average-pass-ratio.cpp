typedef pair<long double,pair<int,int>> ppd;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ppd>pque;
        for(int i=0;i<classes.size();i++)
        {
            pque.push({((classes[i][0]+1)/(long double)(classes[i][1]+1))-(classes[i][0]/(long double)classes[i][1]),{classes[i][0],classes[i][1]}});
        }
        while(extraStudents--)
        {
            auto curr=pque.top();
            pque.pop();
            curr.second.first++;
            curr.second.second++;
            curr.first=((curr.second.first+1)/(long double)(curr.second.second+1))-(curr.second.first/(long double)curr.second.second);
            pque.push(curr);
        }
        double ans=0;
        while(!pque.empty())
        {
            auto curr=pque.top();
            pque.pop();
            ans+=curr.second.first/(long double)curr.second.second;
        }
        return ans/classes.size();
    }
};