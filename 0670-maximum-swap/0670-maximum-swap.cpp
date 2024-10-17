class Solution {
public:
    int maximumSwap(int num) {
        string res=to_string(num),curr=to_string(num);
        for(int i=0;i<curr.size();i++)
        {
            for(int j=i+1;j<curr.size();j++)
            {
                swap(curr[i],curr[j]);
                res=max(res,curr);
                swap(curr[i],curr[j]);
            }
        }
        return stoi(res);
    }
};