class Solution {
public:
    int maximum69Number (int num) {
        vector<int>digit;
        while(num)
        {
            digit.push_back(num%10);
            num/=10;
        }
        int result=0,Pow=pow(10,digit.size()-1);
        bool isFind=0;
        for(int i=digit.size()-1;i>=0;i--)
        {
            if(!isFind&&digit[i]==6)
            {
                digit[i]=9;
                isFind=1;
            }
            result+=Pow*digit[i];
            Pow/=10;
        }
        return result;
    }
};