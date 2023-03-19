class TrieNode
{
    TrieNode *child[26];
    int pre_cnt;
    int end_cnt;
    public:
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                child[i] = nullptr;
            }
            pre_cnt = 0;
            end_cnt = 0;
        }
    void put(char ch, TrieNode *root)
    {
        child[ch - 'a'] = root;
    }
    TrieNode* get(char ch)
    {
        return child[ch - 'a'];
    }
    bool isContainChar(char ch)
    {
        return child[ch - 'a'] != nullptr;
    }
    void increaseEndCnt()
    {
        end_cnt++;
    }
    void increasePreCnt()
    {
        pre_cnt++;
    }
    bool isEnd()
    {
        return end_cnt;
    }
};

class Trie
{

    public:
        TrieNode*root;
        Trie() 
        {
            root=new TrieNode();
        }
    void add(string str)
    {
        TrieNode*curr=root;
        for(int i=0;i<str.size();i++)
        {
            if(!curr->isContainChar(str[i]))
            {
                curr->put(str[i],new TrieNode());
            }
            curr->increasePreCnt();
            curr=curr->get(str[i]);
        }
        curr->increaseEndCnt();
    }
    bool search(int iter,string &str,TrieNode*root)
    {
        if(iter==str.size())
        {
            return root->isEnd();
        }
        if(str[iter]=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(root->isContainChar(i+'a')&&
                   search(iter+1,str,root->get(i+'a')))
                    return true;
            }
            return false;
        }
        if(root->isContainChar(str[iter])&&
           search(iter+1,str,root->get(str[iter])))
            return true;
        return false;       
    }

};

class WordDictionary
{
    Trie trie;
    public:
        WordDictionary() {
        }

    void addWord(string word) {
        trie.add(word);
    }

    bool search(string word) {
        return trie.search(0,word,trie.root);
    }
};

/**
 *Your WordDictionary object will be instantiated and called as such:
 *WordDictionary* obj = new WordDictionary();
 *obj->addWord(word);
 *bool param_2 = obj->search(word);
 */