class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rad,dir;
        int size=senate.size();
        for(int i=0;i<size;i++)
        {
            if(senate[i]=='R')rad.push(i);
            else dir.push(i);
        }
        while(!rad.empty()&&!dir.empty())
        {
            if(rad.front()<dir.front())
            {
                dir.pop();
                rad.push(rad.front()+size);
                rad.pop();
            }
            else
            {
                rad.pop();
                dir.push(dir.front()+size);
                dir.pop();
            }
        }
        return dir.empty()?"Radiant":"Dire";
    }
};