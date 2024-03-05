class Solution {
public:
    int minimumLength(string s) {
        int tail=0,head=(int)s.size()-1;
        while(tail<head)
        {
            if(s[tail]!=s[head])break;
            while(tail<head&&s[tail]==s[tail+1])tail++;
            tail++;
            while(tail<head&&s[head]==s[head-1])head--;
            head--;
        }
        return max(0,head-tail+1);
    }
};