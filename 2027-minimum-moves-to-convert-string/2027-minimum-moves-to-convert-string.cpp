class Solution {
public:
    int minimumMoves(string s) {
        int n=s.size();
        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='O')continue;
            for(int j=i;j<3+i;j++)
            {
                if(j<n&&s[j]=='X')
                {
                    counter++;
                    break;
                }
            }
            i+=2;
        }
        return counter;
    }
};