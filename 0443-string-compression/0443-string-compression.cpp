class Solution {
public:
    int compress(vector<char>& chars) {
        int result=0,inputIter=0;
        for(int i=0;i<chars.size();i++)
        {
            int cntr=0,iter=i;
            while(iter<chars.size()&&chars[iter]==chars[i])
            {
                iter++;
                cntr++;
            }
            i=iter-1;
            chars[inputIter]=chars[i];
            if(cntr==1)
            {
                result++;
                inputIter++;
            }
            else 
            {
                string num=to_string(cntr);
                result+=1+num.size();
                for(int j=0;j<num.size();j++)
                    chars[inputIter+j+1]=num[j];
                inputIter+=1+num.size();
            }
        }
        return result;
    }
};