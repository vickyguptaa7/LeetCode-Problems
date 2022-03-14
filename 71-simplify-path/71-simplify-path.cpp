class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n=path.size();
        int i=0;
        while(i<n&&path[i]=='/')i++;
        string word;
        while(i<n)
        {
            word="";
            while(i<n&&path[i]!='/')
            {
                word+=path[i++];
            }
            
            if(word=="..")
            {
                if(!st.empty())
                  st.pop();
            }
            else
            {            
                if(word!="."){
                  st.push(word);

                }
            }
            while(i<n&&path[i]=='/')i++;
        }
        string res;
        while(!st.empty())
        {
            res="/"+st.top()+res;
            st.pop();
        }
        return (res.size()==0)?"/":res;
    }
};