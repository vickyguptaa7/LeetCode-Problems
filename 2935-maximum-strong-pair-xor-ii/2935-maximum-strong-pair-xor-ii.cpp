class TrieNode
{
    public:
    TrieNode*children[2];
    int count;
    TrieNode()
    {
        children[0]=nullptr;
        children[1]=nullptr;
        count=0;
    }
};

class Trie
{
    TrieNode*root;
    public:
    Trie()
    {
        root=new TrieNode();
    }
    
    void insert(int num)
    {
        TrieNode*curr=root;
        for(int i=20;i>=0;i--)
        {
            int ind=((num)&(1<<i))==0?0:1;
            if(curr->children[ind]==nullptr)
            {
                curr->children[ind]=new TrieNode();
            }
            curr=curr->children[ind];
            curr->count++;
        }
    }
    
    int getMax(int num)
    {
        TrieNode*curr=root;
        int result=0;
        for(int i=20;i>=0;i--)
        {
            int ind=((num)&(1<<i))==0?0:1;
            int opp=(ind==0)?1:0;
            if(curr->children[opp]&&curr->children[opp]->count)
            {
                result+=(1<<i);
                curr=curr->children[opp];
            }
            else
                curr=curr->children[ind];
        }
        return result;
    }
    
    void del(int num)
    {
        TrieNode*curr=root;
        for(int i=20;i>=0;i--)
        {
            int ind=((num)&(1<<i))==0?0:1;
            curr=curr->children[ind];
            curr->count--;
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int right=0,result=0;
        Trie trie;
        for(int i=0;i<nums.size();i++)
        {
            while(right<nums.size()&&nums[right]<=nums[i]*2)
            {
                trie.insert(nums[right]);
                right++;
            }
            result=max(result,trie.getMax(nums[i]));
            trie.del(nums[i]);
        }
        return result;
    }
};