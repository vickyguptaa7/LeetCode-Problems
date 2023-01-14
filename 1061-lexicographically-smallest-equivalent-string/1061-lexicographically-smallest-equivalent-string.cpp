class DisjointSet{
    vector<int>parent,size;
 public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
	}
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node] =findPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int up = findPar(u); 
        int uv = findPar(v); 
        if(up == uv) return; 
        if(up < uv) {
            parent[uv] = up; 
        }
        else {
            parent[up] = uv;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet djs(27);
        for(int i=0;i<s1.size();i++)
        {
            djs.unionBySize(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(auto x:baseStr)
        {
            ans+=char(djs.findPar(x-'a')+'a');
        }
        return ans;
    }
};