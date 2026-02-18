class Solution {
public:

    bool helper(int n,bool init)
    {
        bool isOne=init;
        while(n>0)
        {
            if(isOne!=((n&1)>0))
            {
                return false;
            }
            isOne=!isOne;
            n=n/2;
        }
        return true;
    }

    bool hasAlternatingBits(int n) {
        return helper(n,true)||helper(n,false);
    }
};