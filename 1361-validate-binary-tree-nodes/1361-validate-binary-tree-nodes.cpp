class Solution {
public:
    
    bool dfs(int src,vector<int>list[],vector<bool>&visited)
    {
        if(visited[src]==1)return false;
        visited[src]=1;
        for(auto x:list[src])
        {
           if(!dfs(x,list,visited))return false;
        }
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>list[n];
        vector<int>inorder(n,0);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                list[i].push_back(leftChild[i]);  
                inorder[leftChild[i]]++;
            }
            
            if(rightChild[i]!=-1)
            {
                list[i].push_back(rightChild[i]);
                inorder[rightChild[i]]++;
            }
        }
        int src=0;
        for(int i=0;i<n;i++)
            if(inorder[i]==0)
            {
               src=i;
                break;
            }
        cout<<src<<'\n';
        vector<bool> visited(n,0);
        if(!dfs(src,list,visited))return false;
        for(auto x:visited)if(x==0)return false;
        return true;
    }
};