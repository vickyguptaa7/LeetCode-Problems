//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int>moveX={0,0,-1,1},moveY={1,-1,0,0};
    bool findWord(int x,int y,int indx,string &word,vector<vector<char>>&board,vector<vector<bool>>&visit)
    {
        if(word.size()==indx)
            return true;
        
        if(word[indx]!=board[x][y])
            return false;
            
        visit[x][y]=true;
        
        int row=board.size(),col=board[0].size();
        
        for(int i=0;i<4;i++)
        {
            int _x=moveX[i]+x,_y=moveY[i]+y;
            if(_x>=row||_y>=col||_x<0||_y<0||visit[_x][_y])continue;
            if(findWord(_x,_y,indx+1,word,board,visit))
                return true;
        }
        
        visit[x][y]=false;
        
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size();
        vector<vector<bool>>visit(row,vector<bool>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                    if(findWord(i,j,0,word,board,visit))
                        return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends