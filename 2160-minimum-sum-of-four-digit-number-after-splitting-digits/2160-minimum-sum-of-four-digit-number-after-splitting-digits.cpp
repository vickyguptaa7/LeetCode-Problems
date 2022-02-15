class Solution {
public:
    int minimumSum(int num) {
        map<int,int>omap;
        while(num)
        {
            omap[num%10]++;
            num/=10;
        }
        int num1=0,num2=0;
        int pow=10;
        while(!omap.empty())
        {
            int n=omap.begin()->first;
            num1+=pow*n;
            omap[n]--;
            if(omap[n]==0)
            {
                omap.erase(n);
            }
            n=omap.begin()->first;
            num2+=pow*n;
            omap[n]--;
            if(omap[n]==0)
            {
                omap.erase(n);
            }
            pow/=10;
        }

        return num=num1+num2;
    }
};