class Solution
{
    public:
        double calculateTax(vector<vector < int>> &brackets, int income)
        {
            int n=brackets.size();
            double sum=0;
            if(brackets[0][0]<income)
            {
                sum+=(brackets[0][0]*brackets[0][1])/(double)100;
            }
            else
            {
                return income*brackets[0][1]/(double)100; 
            }
            
            for(int i=1;i<n;i++)
            {
                if(brackets[i][0]<income)
                {
                   sum+=(brackets[i][0]-brackets[i-1][0])*brackets[i][1]/(double)100; 
                }
                else 
                {
                    sum+=(income-brackets[i-1][0])*brackets[i][1]/(double)100;
                    break;
                }
            }
            return sum;
        }
};