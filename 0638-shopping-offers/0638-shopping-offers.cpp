class Solution
{
    public:

        int helper(int strt, vector<int> &price, vector<int> &needs,
            vector<vector < int>> &special)
        {
            if (strt == special.size())
            {
                int cost = 0;
                for (int i = 0; i < price.size(); i++)
                {
                    cost += needs[i] *price[i];
                }
                return cost;
            }
            int skipCost = helper(strt + 1, price, needs, special);
            bool isPossible = true;
            int n=needs.size();
            for (int i = 0; i < n; i++)
            {
                if (special[strt][i] > needs[i])
                {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible)
            {
                for (int i = 0; i < n; i++)
                {
                    needs[i] -= special[strt][i];
                }
                int considerCost=helper(strt,price,needs,special)+
                    special[strt][n];
                for (int i = 0; i < n; i++)
                {
                    needs[i] += special[strt][i];
                }
                return min(considerCost,skipCost);
            }
            return skipCost;
        }
    int shoppingOffers(vector<int> &price, vector<vector< int >> &special, vector< int > &needs)
    {
        int n = price.size();
        return helper(0, price, needs, special);
    }
};