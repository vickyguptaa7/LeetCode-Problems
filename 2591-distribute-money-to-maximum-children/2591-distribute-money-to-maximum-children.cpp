class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children)
            return -1;
        money-=children;
        if(money==children*7)
        {
            return children;
        }
        if(money>=children*7)
        {
            return children-1;
        }
        if(money>=(children-1)*7+4)
        {
            return children-1;
        }
        if(money<=(children-1)*7+2&&money>=(children-1)*7)
        {
            return children-1;
        }
        if(money==(children-1)*7+3)
            return children-2;
        return money/7;
    }
};