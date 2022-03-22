class Solution {
public:

    string getSmallestString(int n, int k) {
        string result;
        char ch;
        for(int i=0;i<n;i++)
        {
            int temp=k-(n-i-1);
            if(temp>=26)
            {
                result+="z";
                k-=26;
            }
            else
            {
                ch='a'+temp-1;
                result+=ch;
                k-=temp;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
};