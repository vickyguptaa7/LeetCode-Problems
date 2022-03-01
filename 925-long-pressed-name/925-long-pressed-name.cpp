class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int iter1=0,iter2=0;
       
        int n1=name.size(),n2=typed.size();
        if(n1>n2)return false;
        
        while(iter1<n1)
        {
            int freq=1;
            iter1++;
            while(iter1<n1&&name[iter1-1]==name[iter1])
            {
                freq++;
                iter1++;
            }

            while(iter2<n2&&name[iter1-1]==typed[iter2])
            {
                freq--;
                iter2++;
            }
            
            if(freq>0)
            {
                return false;
            }
        }
        if(iter2!=n2)return false;
        return true;
    }
};