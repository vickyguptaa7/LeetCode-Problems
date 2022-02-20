class Solution {
public:
    string maximumTime(string time) {
        char h1=time[0],h2=time[1],m1=time[3],m2=time[4];
        if(h1=='?')
        {
            if(h2<'4'||h2=='?')
            {
                h1='2';
            }
            else
            {
                h1='1';
            }
        }
        if(h2=='?')
        {
            if(h1=='2')
            {
                h2='3';
            }
            else
            {
                h2='9';
            }
        }
        if(m1=='?')
        {
            m1='5';
        }
        if(m2=='?')
        {
            m2='9';
        }
        time[0]=h1;
        time[1]=h2;
        time[3]=m1;
        time[4]=m2;
        return time;
        
    }
};