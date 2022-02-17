class Solution {
public:
    int minTimeToType(string word) {
        int result=word.length();
        int n=result;
        char initial='a';
        for(int i=0;i<n;i++)
        {
            char Final=word[i];
            int steps=abs(initial-Final);
            steps=(steps<abs(26-steps))?steps:abs(26-steps);
            result+=steps;
            initial=Final;
        }
        return result;
    }
};