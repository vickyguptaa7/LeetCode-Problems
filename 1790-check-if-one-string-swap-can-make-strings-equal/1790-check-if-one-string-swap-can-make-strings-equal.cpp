class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int indx1=-1,indx2=-1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(indx1==-1)
                {
                    indx1=i;
                }
                else if(indx2==-1)
                {
                    indx2=i;
                }
                else
                {
                    return false;
                }
            }
        }
        if(indx1==-1)
            return true;
        else if(indx2==-1)
            return false;
        return s1[indx1]==s2[indx2]&&s1[indx2]==s2[indx1];
    }
};