//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> freq(26,0);
		    queue<char>que;
		    string ans="";
		    for(int i=0;i<A.size();i++)
		    {
		        freq[A[i]-'a']++;
		        que.push(A[i]);
		        while(!que.empty()&&freq[que.front()-'a']>1)
		        {
		            que.pop();
		        }
		        if(que.empty())
		        {
		            ans+="#";
		        }
		        else
		        {
		            ans+=que.front();
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends