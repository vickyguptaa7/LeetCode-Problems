class StockPrice {
public:
    map<int,int>stockPrice,prices;
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(stockPrice.count(timestamp))
        {
            prices[stockPrice[timestamp]]--;
            if(prices[stockPrice[timestamp]]==0)
                prices.erase(stockPrice[timestamp]);
        }
        prices[price]++;
        stockPrice[timestamp]=price;
    }
    
    int current() {
        return stockPrice.rbegin()->second;
    }
    
    int maximum() {
        return prices.rbegin()->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */