class Solution {
public:
    int isPal(string s,int left,int right)
    {
        if(left<0||right>=s.size())return false;
        int cnt=0;
        while(left>=0&&right<s.size())
        {
            if(s[left]!=s[right])
            {
                break;
            }
            left--;
            right++;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int result=n;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                result+=isPal(s,i-1,i);
            }
            result+=isPal(s,i-1,i+1);
        }
        return result;
    }
};