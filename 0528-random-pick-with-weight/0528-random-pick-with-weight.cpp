class Solution {
public:
    vector<int>pwght;
    int sum,size;
    Solution(vector<int>& w) {
        pwght=w;
        for(int i=1;i<w.size();i++)
        {
            pwght[i]+=pwght[i-1];
        }
    }
    
    int pickIndex() {
        int rnd=rand()%pwght.back();
        return upper_bound(pwght.begin(),pwght.end(),rnd)-pwght.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */