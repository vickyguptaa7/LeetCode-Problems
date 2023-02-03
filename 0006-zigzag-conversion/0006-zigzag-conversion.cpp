class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string>srr(numRows,"");
        int row=0;
        bool isIncrement=true;
        for(int i=0;i<s.size();i++)
        {
            if(isIncrement)
            {
                srr[row]+=s[i];
                row++;
                if(numRows==row)
                {
                    isIncrement=false;
                    row-=2;
                }
            }
            else 
            {
                srr[row]+=s[i];
                row--;
                if(row==-1)
                {
                    isIncrement=true;
                    row+=2;
                }
            }
        }
        string result;
        for(auto &word:srr)
            result+=word;
        return result;
    }
};