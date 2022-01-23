class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        vector<int>digit={1,2,3,4,5,6,7,8,9};
        for(int i=1;i<=9;i++)
        {
            string s;
            int temp=0;
            while(temp<i)
            {
                s+=to_string(digit[temp++]);
            }
            int num=stoi(s);
            if(num>=low&&num<=high)
            ans.push_back(num);
            for(int j=i;j<9;j++)
            {
                s=s.substr(1);
                s+=to_string(digit[j]);
                num=stoi(s);
                if(num<low||num>high)
                continue;
                ans.push_back(num);
            }
        }
        return ans;
    }
};