class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int Max=0;
        for(int i=0;i<strs.size();i++)
        {
            bool isNum=true;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]<'0'||strs[i][j]>'9')
                {
                    isNum=false;
                    break;
                }
            }
            if(isNum)
            {
                Max=max(Max,stoi(strs[i]));
            }
            else 
            {
                Max=max(Max,(int)strs[i].size());
            }
        }
        return Max;
    }
};