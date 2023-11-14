class node {
    public:
    node *arr[2];
    int end;
    node()
    {
        arr[0]=nullptr;
        arr[1]=nullptr;
        end=0;
    }
};

class Trie
{
  node* nd;
    public:
    Trie()
    {
        nd=new node();
    }
    
    void insert(string s)
    {
        node*curr=nd;
        for(int i=0;i<s.size();i++)
        {
            if(curr->arr[s[i]-'0'])
            {
                curr=curr->arr[s[i]-'0'];
            }
            else
            {
                node*newnode=new node();
                curr->arr[s[i]-'0']=newnode;
                curr=newnode;
            }
        }
    }
    
    int search(string s)
    {
        node*curr=nd;
        int result=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int find=(s[i]-'0'==0)?1:0;
            if(curr->arr[find])
            {
                curr=curr->arr[find];
                result|=(1<<(n-i-1));
            }
            else
            {
                curr=curr->arr[!find];
            }
        }
        return result;
    }
};

class Solution {
public:
    
    string decimalToBinary(int num)
    {
        string s="";
        while(num)
        {
            s+=(num&1)?'1':'0';
            num/=2;
        }
        reverse(s.begin(),s.end());
        string zero;
        for(int i=s.size();i<=30;i++)
            zero+="0";
        return zero+s;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto& num:nums)
        {
            trie.insert(decimalToBinary(num));
        }
        int result=0;
        for(auto& num:nums)
        {
            result=max(result,trie.search(decimalToBinary(num)));
        }
        return result;
    }
};