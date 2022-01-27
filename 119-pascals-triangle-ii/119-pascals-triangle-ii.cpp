class Solution {
public:
    vector<int>nCr(int n)
    {
        vector<int>result;
        result.push_back(1);
        if(n==0)return result;
        for(int i=1;i<n;i++)
        {
            long long coef=1;int temp=n;
            for(int j=1;j<=i;j++)
            {
               coef*=temp--;
                coef/=j;
            }
            result.push_back(coef);
        }
        result.push_back(1);
        return result;
    }
    vector<int> getRow(int rowIndex) {
        return nCr(rowIndex);
    }
};