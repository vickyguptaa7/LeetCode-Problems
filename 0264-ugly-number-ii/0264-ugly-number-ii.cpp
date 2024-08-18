class Solution {
public:
    
    int nthUglyNumber(int n) {
        set<long long>pque;
        pque.insert(1);
        int cntr=1;
        while(cntr<n)
        {
            pque.insert(*pque.begin()*2);
            pque.insert(*pque.begin()*3);
            pque.insert(*pque.begin()*5);
            pque.erase(pque.begin());
            cntr++;
        }
        return *pque.begin();
    }
    // 25 -> 2-12 3-8 5-5 6-4 10-2 15-1 30-0
    // 25 -> 1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 
};