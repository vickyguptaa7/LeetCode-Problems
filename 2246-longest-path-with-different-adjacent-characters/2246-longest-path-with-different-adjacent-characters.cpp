class Solution {
public:
    
    int helper(int src,int par,vector<int>list[],string &s,int &diameter)
    {
        int hieght=0;
        priority_queue<int>pque;
        for(auto curr:list[src])
        {
            if(curr!=par)
            {
                if(s[curr]==s[src])
                {
                    pque.push(0);
                    helper(curr,src,list,s,diameter);
                }
                else
                {
                    pque.push(helper(curr,src,list,s,diameter));
                }
            }
        }
        int h1=0,h2=0;
        if(!pque.empty())
        {
            h1=pque.top();
            pque.pop();
        }
        if(!pque.empty())
        {
            h2=pque.top();
            pque.pop();
        }
        
        diameter=max(diameter,h1+h2+1);
        return max(h1,h2)+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<int>list[n];
        for(int i=1;i<n;i++)
        {
            list[i].push_back(parent[i]);
            list[parent[i]].push_back(i);
        }
        int diameter=0;
        helper(0,-1,list,s,diameter);
        return diameter;
    }
};