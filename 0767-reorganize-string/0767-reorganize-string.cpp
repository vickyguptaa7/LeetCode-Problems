class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(auto& ch:s)freq[ch-'a']++;
        priority_queue<pair<int,char>>pque;
        for(int i=0;i<26;i++)
            if(freq[i])
            pque.push({freq[i],i+'a'});

        string res;
        while(pque.size()>1)
        {
            auto p1=pque.top();
            pque.pop();
            auto p2=pque.top();
            pque.pop();
            res+=p1.second;
            res+=p2.second;
            if(p1.first>1)
            {
                pque.push({p1.first-1,p1.second});
            }
            if(p2.first>1)
            {
                pque.push({p2.first-1,p2.second});
            }
        }
        
        if(!pque.empty())
        {
            if(pque.top().first>1)
                return "";
            res+=pque.top().second;
            pque.pop();
        }
        return res;
    }
};