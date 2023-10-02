class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0;
        int cnt=1;
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                cnt++;
            }
            else
            {
                if(cnt>2)
                {
                    if(colors[i-1]=='A')alice+=cnt-2;
                    else 
                        bob+=cnt-2;
                }
                cnt=1;
            }
        }
        if(cnt>2)
        {
            if(colors.back()=='A')alice+=cnt-2;
            else 
                bob+=cnt-2;
        }
        return alice>bob;
    }
};