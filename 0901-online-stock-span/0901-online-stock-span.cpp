class StockSpanner {
public:
    stack<int>stock;
    vector<int>prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!stock.empty()&&prices[stock.top()]<=price)
        {
            stock.pop();
        }
        int curr=(stock.empty()?prices.size()+1:prices.size()-stock.top());
        stock.push(prices.size());
        prices.push_back(price);
        return curr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */