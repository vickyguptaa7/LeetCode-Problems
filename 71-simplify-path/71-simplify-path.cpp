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
        vector<string>store;
        while(!st.empty())
        {
            store.push_back(st.top());
            st.pop();
        }
        reverse(store.begin(),store.end());
        string res;
        for(auto x:store)
        {
            res=res+"/"+x;
        }
        return (res.size()==0)?"/":res;
    }
};