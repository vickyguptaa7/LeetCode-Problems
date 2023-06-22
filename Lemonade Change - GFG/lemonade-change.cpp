//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int fiveCoins=0,tenCoins=0,twentyCoins=0;
        for(int i=0;i<N;i++)
        {
            int amount=bills[i];
            if(amount==5)
                fiveCoins++;
            else if(amount==10)
            {
                if(fiveCoins>0)
                {
                    fiveCoins--;
                    tenCoins++;
                }
                else 
                    return false;
            }
            else 
            {
                if(fiveCoins>0&&tenCoins>0)
                {
                    fiveCoins--;
                    tenCoins--;
                    twentyCoins++;
                }
                else if(fiveCoins>2)
                {
                    fiveCoins-=3;
                    twentyCoins++;
                }
                else 
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends