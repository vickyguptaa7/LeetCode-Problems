class Solution {
public:
    int nextGreaterElement(int n) {
        if(n==2147483647)return -1;
        
        string num=to_string(n);
        int i;
        for(i=num.size()-1;i>=1;i--)
        {
            if(num[i]>num[i-1])break;
        }
        if(i==0)return -1;
        i--;
        int j;
        for(j=num.size()-1;j>=i;j--)
        {
            if(num[j]>num[i])break;
        }
        swap(num[i],num[j]);
        reverse(num.begin()+i+1,num.end());
        long answer=stol(num);
        if(answer>2147483647)return -1;
            return answer;
    }
};
//230241