class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size=cards.size();
        int minCardPick=size;
        unordered_set<int>uset;
        int prev=0;
        bool isFind=false;
        for(int i=0;i<size;i++)
        {
            if(uset.count(cards[i]))
            {
                while(uset.count(cards[i]))
                {
                    uset.erase(cards[prev++]);
                }
                minCardPick=min(minCardPick,i-prev+2);
                isFind=true;
            }
            uset.insert(cards[i]);
        }
        return isFind?minCardPick:-1;
    }
};