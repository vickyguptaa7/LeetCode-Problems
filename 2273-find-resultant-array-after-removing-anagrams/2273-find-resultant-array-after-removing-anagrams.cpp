class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<pair<int,string>>temp;
        int i=0;
        for(auto x:words)
        {
            string s=x;
            sort(s.begin(),s.end());
            temp.push_back({i,s});
            i++;
        }
        stack<pair<int,string>>st;
        for(int i=0;i<temp.size();i++)
        {
            if(!st.empty()&&st.top().second==temp[i].second)continue;
            st.push(temp[i]);
        }
        temp.clear();
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.begin(),temp.end());
        vector<string>ans;
        for(auto x:temp)ans.push_back(words[x.first]);
        return ans;
    }
};