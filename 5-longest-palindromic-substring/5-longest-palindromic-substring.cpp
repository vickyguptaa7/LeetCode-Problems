class Solution {
public:
    vector<vector<int>>isPal(string s)
    {
        int n=s.length();
        
        vector<vector<int>>isPall(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)isPall[i][i]=1;
        
        for(int size=2;size<=n;size++)
        {
            for(int left=0;left<n-size+1;left++)
            {
                int right=left+size-1;
                if(s[left]==s[right])
                {
                    if(size==2)
                    isPall[left][right]=2;
                    else 
                    {
                        int temp=isPall[left+1][right-1];
                        if(temp>0)isPall[left][right]=2+temp;
                        else isPall[left][right]=temp;
                    }
                }
            }
        }
        return isPall;
    }
    string longestPalindrome(string s) {
        vector<vector<int>>isPallindrome=isPal(s);
        int ii=0,jj=0,max_size=1,n=s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(max_size<isPallindrome[i][j])
                {
                    ii=i;jj=j;
                    max_size=isPallindrome[i][j];
                }
            }
        }
        string ans;
        for(int i=ii;i<=jj;i++)
        {
            ans+=s[i];
        }
        return ans;
    }
};