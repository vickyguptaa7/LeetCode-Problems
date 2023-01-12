class Solution {
public:
    int magicalString(int n) {
        int oneCnt=1;
        string s="122";
        bool isOne=true;
        for(int i=2;i<n;i++)
        {
            s+=(isOne)?"1":"2";
            if(s[i]=='2')
            {
                s+=(isOne)?"1":"2";
            }
            isOne=!isOne;
            oneCnt+=(s[i]=='1')?1:0;
        }
        return oneCnt;
    }
};