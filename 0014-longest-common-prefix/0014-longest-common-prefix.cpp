class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=(int)strs[0].size();
        for(int i=1;i<strs.size();i++)
        {
            int size=min(len+1,(int)strs[i].size());
            for(int j=0;j<size;j++)
            {
                if(strs[i][j]!=strs[0][j])
                {
                    len=min(len,j);
                    break;
                }
            }
            len=min(len,size);
        }
        return strs[0].substr(0,len);
    }
};