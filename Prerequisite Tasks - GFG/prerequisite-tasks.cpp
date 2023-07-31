//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>list[N];
	    vector<int>inorder(N,0);
	    for(int i=0;i<P;i++)
	    {
	        list[prerequisites[i].second].push_back(prerequisites[i].first);
	        inorder[prerequisites[i].first]++;
	    }
	    queue<int>que;
	    vector<int>visited(N,0);
	    for(int i=0;i<N;i++)
	    {
	        if(inorder[i]==0)
	        {
	            visited[i]=true;
	            que.push(i);
	        }
	    }
	    while(!que.empty())
	    {
	        int curr=que.front();
	        que.pop();
	        for(auto child:list[curr])
	        {
	            inorder[child]--;
	            if(inorder[child]!=0)continue;
	            visited[child]=true;
	            que.push(child);
	        }
	    }
	    for(int i=0;i<N;i++)
	    {
	        if(inorder[i]>0)
	        return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends