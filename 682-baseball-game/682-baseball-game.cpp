class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                ans.pop_back();
            }
            else if(ops[i]=="D")
            {
                ans.push_back((ans[ans.size()-1])*2);
            }
            else if(ops[i]=="+")
            {
                ans.push_back(ans[ans.size()-2]+ans[ans.size()-1]);
            }
            else 
            {
                ans.push_back(stoi(ops[i]));
            }
        }
        int res=0;
        res=accumulate(ans.begin(),ans.end(),0);
        return res;
    }
};