class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>result;
        vector<int>freq(51,0);
        int cmn=0;
        for(int i=0;i<A.size();i++)
        {
            cmn+=(++freq[A[i]]==2);
            cmn+=(++freq[B[i]]==2);
            result.push_back(cmn);
        }
        return result;
    }
};