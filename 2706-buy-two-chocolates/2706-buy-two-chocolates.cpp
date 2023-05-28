class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstMinChoc=1e9,secondMinChoc=1e9;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<firstMinChoc)
            {
                secondMinChoc=firstMinChoc;
                firstMinChoc=prices[i];
            }
            else 
            {
                secondMinChoc=min(secondMinChoc,prices[i]);
            }
        }
        return (money-(firstMinChoc+secondMinChoc))>=0?
            money-(firstMinChoc+secondMinChoc):money;
    }
};