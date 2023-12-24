class Solution {
public:
    int minOperations(string s) {
        int zfc=0,ofc=0;
        for(int i=0;i<s.size();i++)
        {
            if(i&1)
            {
                if(s[i]=='0')
                {
                    zfc++;
                }
                else
                {
                    ofc++;
                }
            }
            else
            {
                if(s[i]=='0')
                {
                    ofc++;
                }
                else
                {
                    zfc++;
                }
            }
        }
        return min(zfc,ofc);
    }
};