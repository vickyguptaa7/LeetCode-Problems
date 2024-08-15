class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount=0,tenCount=0,twentyCount=0;
        for(auto &bill:bills)
        {
            if(bill==5)
                fiveCount++;
            else if(bill==10)
            {
                if(!fiveCount)return false;
                fiveCount--;
                tenCount++;
            }
            else 
            {
                if(fiveCount&&tenCount)
                {
                    fiveCount--;
                    tenCount--;
                }
                else if(fiveCount>2)
                {
                    fiveCount-=3;
                }
                else
                {
                    return false;
                }
                twentyCount++;
            }
        }
        return true;
    }
};