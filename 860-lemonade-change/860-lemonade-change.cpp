class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int freq[2]={0};
        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                freq[0]++;
            }
            else if(bills[i]==10)
            {
                if(freq[0]==0)return false;
                freq[0]--;
                freq[1]++;
            }
            else
            {
                if((freq[0]>=3)||(freq[0]>0&&freq[1]>0))
                {
                    if(freq[1]!=0)
                    {
                        freq[1]--;
                        freq[0]--;
                    }
                    else
                    {
                        freq[0]-=3;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};