class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastIndex;
        for(int i=0;i<s.size();i++)
        {
            lastIndex[s[i]]=i;
        }
        vector<int>res;
        int lindx=0,strt=0;
        for(int i=0;i<s.size();i++)
        {
            lindx=max(lastIndex[s[i]],lindx);
            if(i==lindx)
            {
                res.push_back(lindx-strt+1);
                strt=lindx+1;
            }
        }
        return res;
    }
};

/*
    vector<pair<int,int>>Interval(string s)
    {
        unordered_map<int,pair<int,int>>umap;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(umap.find(s[i])==umap.end())
            {
                umap[s[i]]={i,i+1};
            }
            else
            {
                umap[s[i]].second=i+1;
            }
        }
        vector<pair<int,int>>interval;
        for(auto &x:umap)
        {
            interval.push_back(x.second);
        }
        sort(interval.begin(),interval.end());
        return interval;
    }
    vector<pair<int,int>>Merge_Interval(vector<pair<int,int>>&Interval)
    {
        vector<pair<int,int>>newInterval;
        stack<pair<int,int>>stack;
        stack.push(Interval[0]);
        int n=Interval.size();
        for(int i=1;i<n;i++)
        {
            pair<int,int>itrvl=stack.top();
            stack.pop();
            if(Interval[i].first<itrvl.second)
            {
                itrvl.second=max(itrvl.second,Interval[i].second);
                stack.push(itrvl);
            }
            else
            {
                stack.push(itrvl);
                stack.push(Interval[i]);
            }
        }
        cout<<stack.size()<<"\n";
        while(!stack.empty())
        {
            newInterval.push_back(stack.top());
            stack.pop();
        }
        sort(newInterval.begin(),newInterval.end());
        return newInterval;
    }
    vector<int> partitionLabels(string s) {
        int n=s.length();
        
        vector<pair<int,int>>interval=Interval(s);
        
        vector<pair<int,int>>merge_interval=Merge_Interval(interval);
        vector<int>result;
        for(auto x:merge_interval)
        {
            result.push_back(x.second-x.first);
        }
        return result;
    }
*/