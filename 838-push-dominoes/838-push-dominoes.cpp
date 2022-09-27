class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> left,right;
        int n=dominoes.size(),indx=-1;
        char ch='.';
        for(int i=0;i<n;i++)
        {
            left.push_back(indx);
            if(dominoes[i]!='.')
                ch=dominoes[i],indx=i;
        }
        ch='.';
        indx=-1;
        for(int i=n-1;i>=0;i--)
        {
            right.push_back(indx);
            if(dominoes[i]!='.')
                ch=dominoes[i],indx=i;
        }
        reverse(right.begin(),right.end());
        string result;
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]!='.')
            {
                result+=dominoes[i];
                continue;
            }
            if(left[i]!=-1&&dominoes[left[i]]=='R')
            {
                if(right[i]!=-1&&dominoes[right[i]]=='L')
                {
                    if(i-left[i]==right[i]-i)
                        result+='.';
                    else if(i-left[i]>right[i]-i) 
                        result+='L';
                    else
                        result+='R';
                }
                else
                {
                    result+='R';
                }
            }
            else
            {
                if(right[i]!=-1&&dominoes[right[i]]=='L')
                {
                    result+='L';
                }
                else
                {
                    result+='.';
                }
            }
        }
        return result;
    }
};