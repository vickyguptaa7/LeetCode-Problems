class Solution {
public:
    int minFlips(int a, int b, int c) {
        int oper=0;
        for(int i=0;i<31;i++)
        {
            if(c&(1<<i))
            {
                if(!(a&(1<<i))&&!(b&(1<<i)))
                {
                   oper++; 
                }
            }
            else 
            {
                if(a&(1<<i))
                {
                   oper++; 
                }
                if(b&(1<<i))
                {
                   oper++; 
                }
            }
        }
        return oper;
    }
};