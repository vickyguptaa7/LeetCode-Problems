class ProductOfNumbers {
public:
    vector<long long>product_prefix;
    vector<long long>zero_prefix_sum;

    ProductOfNumbers() {
        // maintain zero count prefix sum
        // maintain product prefix
        product_prefix.push_back(1);
        zero_prefix_sum.push_back(0);
    }
    
    void add(int num) {
        product_prefix.push_back(num==0?1:num*product_prefix.back());
        zero_prefix_sum.push_back(num==0?1+zero_prefix_sum.back():zero_prefix_sum.back());
    }
    
    int getProduct(int k) {
        int size=product_prefix.size();
        if(zero_prefix_sum.back()-zero_prefix_sum[size-k-1])
            return 0;
        return product_prefix.back()/product_prefix[size-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */