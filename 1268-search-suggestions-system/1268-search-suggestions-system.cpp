class TrieNode
{
    TrieNode *childs[26];
    vector<int> wordIndx;
    public:
        TrieNode()
        {
            for (int i = 0; i < 26; i++) childs[i] = nullptr;
        }
    
    TrieNode*get(char ch)
    {
        return childs[ch-'a'];
    }
    
    void put(char ch,TrieNode*root)
    {
        childs[ch-'a']=root;
    }
    
    void putIndx(int i)
    {
         wordIndx.push_back(i);
    }
    
    vector<int>getIndx()
    {
        return wordIndx;
    }
};

class Trie
{
    TrieNode * root;
    public:
        Trie()
        {
            root = new TrieNode();
        }

    void Insert(string s, int idx)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            curr->putIndx(idx);
            if (curr->get(s[i]) == nullptr)
            {
                curr->put(s[i], new TrieNode());
                curr = curr->get(s[i]);
            }
            else
            {
                curr=curr->get(s[i]);
            }
        }
        curr->putIndx(idx);
    }

    vector<int> Search(string s)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            curr = curr->get(s[i]);
            if(curr==nullptr)return {};
        }
        return curr->getIndx();
    }
};

class Solution
{
    public:
        vector<vector < string>> suggestedProducts(vector<string> &products, string searchWord)
        {
            sort(products.begin(), products.end());
            Trie prefix;
            
            for(int i=0;i<products.size();i++)
            {
                prefix.Insert(products[i],i);
            }

            vector<vector < string>> res;
            string str;
            for (int i = 0; i < searchWord.size(); i++)
            {
                str += searchWord[i];
                vector<int> idx = prefix.Search(str);
                vector<string> row;
                for (int j = 0;j < min((int)idx.size(), 3); j++)
                {
                    row.push_back(products[idx[j]]);
                }
                res.push_back(row);   
            }
            return res;
        }
};