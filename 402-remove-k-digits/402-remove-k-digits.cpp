class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.length();
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&k>0&&st.top()>num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        string res="";
        while(!st.empty())
        {
            if(k>0)
            {
                k--;
                st.pop();
                continue;
            }
            res=st.top()+res;
            st.pop();
        }
        while(res[0]=='0')
        {
            res.erase(0,1);
        }
        if(res.size()==0)return "0";
        return res;
    }
//         string removeKdigits(string num, int k) {
//         for(int i=1;i<num.length();i++)
//         {
//             if(num[i-1]>num[i])
//             {
//                 num.erase(i-1,1);
//                 k--;
//                 if(i>=2)
//                 i-=2;
//                 else
//                     i--;
//             }
//             if(k==0)
//             {
//                 break;
//             }
//         }
        
//         num=num.substr(0,num.length()-k);
        
//         int iter=0;
//         while(num[iter]=='0')
//         {
//             num.erase(0,1);
//         }
//         if(num.length()==0)
//         {
//             return "0";
//         }
//         return num;
//     }
};