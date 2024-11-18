class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        bool isNeg=k<0;
        k=abs(k);
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=1;j<=k;j++)
            {
                int indx=isNeg?i-j:i+j;
                indx=(indx%n+n)%n;
                sum+=code[indx];
            }
            res.push_back(sum);
        }
        return res;
    }
};