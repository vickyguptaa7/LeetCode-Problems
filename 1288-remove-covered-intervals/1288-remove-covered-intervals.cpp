bool mycomp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]!=v2[0])
    {
        return v1[0]<v2[0];
    }
    return v1[1]<v2[1];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intr) {
        sort(intr.begin(),intr.end(),mycomp);
        int size=intr.size();
        int left=0;
        for(int i=1;i<size;i++)
        {
        if (intr[left][0] >= intr[i][0] && intr[left][1] <= intr[i][1])
        {
            intr[left][0] = intr[i][0];
            intr[left][1] = intr[i][1];
        }
        else if (intr[left][0] <= intr[i][0] && intr[left][1] >= intr[i][1])
        {
            continue;
        }
        else
        {
            left++;
            intr[left][0] = intr[i][0];
            intr[left][1] = intr[i][1];
        }
        }
        return left+1;
    }
};