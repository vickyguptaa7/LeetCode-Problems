typedef pair<int,int> ppi;

struct Mycomp
{
    bool operator()(ppi&a,ppi&b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        priority_queue<ppi,vector<ppi>,Mycomp>pque;
        long long iter=0,n=tasks.size(),time=tasks[0][0];
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            if(tasks[0][0]==tasks[i][0])
            {
                pque.push({tasks[i][1],tasks[i][2]});
                iter++;
            }
            else
                break;
        }
        while(result.size()<n)
        {
            time+=pque.top().first;
            result.push_back(pque.top().second);
            pque.pop();
            while(iter<n&&time>=tasks[iter][0])
            {
                pque.push({tasks[iter][1],tasks[iter][2]});
                iter++;
            }
            if(pque.empty()&&iter!=n)
            {
                pque.push({tasks[iter][1],tasks[iter][2]});
                time=tasks[iter][0];
                iter++;
            }
        }
        return result;
    }
};