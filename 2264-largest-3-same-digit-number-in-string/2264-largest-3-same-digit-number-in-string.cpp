class Solution {
public:
    string largestGoodInteger(string num) {
        string res="";
        for(int i=2;i<num.size();i++)
        {
            if(num[i-2]!=num[i]||num[i-1]!=num[i])
                continue;
            string curr="";
            curr+=num[i-2];
            curr+=num[i-1];
            curr+=num[i];
            res=max(curr,res);
        }
        return res;
    }
};