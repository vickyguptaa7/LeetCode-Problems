class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>oset(wordList.begin(),wordList.end());
        unordered_map<string,bool>visited;
        queue<string>que;
        que.push(beginWord);
        int length=1;
        visited[beginWord]=1;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                string curr=que.front();
                que.pop();
                if(curr==endWord)
                    return length;
                for(int i=0;i<curr.size();i++)
                {
                    for(int j=0;j<26;j++)
                    {
                        string str=curr.substr(0,i)+char(j+'a')+curr.substr(i+1);
                        if(!oset.count(str)||visited[str])
                            continue;
                        visited[str]=true;
                        que.push(str);
                    }
                }
            }
            length++;
        }
        return 0;
    }
};