class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len=columnTitle.size();
        int res=0;
        for(int i=0;i<len;i++)
        {
            int left=columnTitle[i]-'A'+1;
            res=res*26+left;
        }
        return res;
    }
};