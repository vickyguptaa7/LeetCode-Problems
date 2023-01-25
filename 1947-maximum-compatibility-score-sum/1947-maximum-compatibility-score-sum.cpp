class Solution {
public:
    int helper(int iter,vector<vector<int>>&students,vector<vector<int>>&mentors
              ,int mask)
    {
        if(iter==students.size())
        {
            return 0;
        }
        int mxAns=0;
        for(int i=0;i<mentors.size();i++)
        {
            if(!(mask&(1<<i)))
            {
                int tempAns=0;
                for(int j=0;j<students[iter].size();j++)
                {
                    if(students[iter][j]==mentors[i][j])
                    {
                        tempAns++;
                    }
                }
                mxAns=max(mxAns,tempAns+helper(iter+1,students,mentors,
                                               mask|(1<<i)));
            }
        }
        return mxAns;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        return helper(0,students,mentors,0);
    }
};