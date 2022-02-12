class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool>vmap;
        for(int i=0;i<wordList.size();i++)
        {
            vmap[wordList[i]]=0;
        }
        queue<string>que;
        que.push(beginWord);
        vmap[beginWord]=1;
        int count=1;
        while(que.size())
        {
            int size=que.size();
            while(size--)
            {
                string node=que.front();
                que.pop();
                if(node==endWord)
                {
                    return count;
                }
                for(int i=0;i<node.length();i++)
                {
                    for(int j=0;j<26;j++)
                    {
                        char ch=97+j;
                        string newnode=node.substr(0,i)+ch+node.substr(i+1);
                        
                        if(node[i]!=ch&&vmap.find(newnode)!=vmap.end()&&
                           vmap[newnode]!=1)
                        {
                            vmap[newnode]=1;
                            que.push(newnode);
                            
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};