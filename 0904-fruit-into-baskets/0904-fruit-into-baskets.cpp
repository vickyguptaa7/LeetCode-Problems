class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits=0,prev=0;
        unordered_map<int,int>freq;
        for(int i=0;i<fruits.size();i++)
        {
            freq[fruits[i]]++;
            while(freq.size()>2)
            {
                freq[fruits[prev]]--;
                if(freq[fruits[prev]]==0)
                    freq.erase(fruits[prev]);
                prev++;
            }
            maxFruits=max(maxFruits,i-prev+1);
        }
        return maxFruits;
    }
};