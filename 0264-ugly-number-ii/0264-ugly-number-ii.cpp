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
};