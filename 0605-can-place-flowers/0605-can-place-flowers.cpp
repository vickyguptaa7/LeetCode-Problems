class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        if(flowerbed.size()==1)
        {
            if(n==1)
                return flowerbed[0]==0;
            return false;
        }
        int strt=1;
        if(flowerbed[0]==0&&flowerbed[1]==0)
        {
            n--;
            strt++;
        }
        for(int i=strt;i<(int)flowerbed.size()-1;i++)
        {
            if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0)
            {
                i++;
                n--;
            }
            strt=i+1;
        }
        if(strt==(int)flowerbed.size()-1&&flowerbed[strt]==0
           &&flowerbed[strt-1]==0)
        {
            n--;
        }
        return n<=0;
    }
};