class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cntr=0;
        while(startValue!=target)
        {
            if(target%2==0&&target>startValue)
            {
                target/=2;
            }
            else 
            {
                target++;
            }
            cntr++;
        }
        return cntr;
    }
};