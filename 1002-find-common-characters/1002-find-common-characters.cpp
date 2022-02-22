class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int>umap;
        string word=words[0];
        for(int i=0;i<word.size();i++)
        {
            umap[word[i]]++;
        }
        
        for(int i=1;i<words.size();i++)
        {
            word=words[i];
            unordered_map<char,int>umap2=umap;
            for(int i=0;i<word.size();i++)
            {
               if(umap2.find(word[i])!=umap2.end())
               {
                   if(umap2[word[i]]!=0)
                       umap2[word[i]]--;
               }
            }
            unordered_map<char,int>newMp;
            for(auto x:umap2)
            {
                if(x.second==0||x.second<umap[x.first])
                {
                    newMp[x.first]=umap[x.first]-x.second;
                }
            }
            umap=newMp;
        }
        vector<string>res;
        for(auto x:umap)
        {
            for(int i=0;i<x.second;i++)
            {
                string temp;
                temp+=x.first;
                res.push_back(temp);
            }
        }
        return res;
    }
};