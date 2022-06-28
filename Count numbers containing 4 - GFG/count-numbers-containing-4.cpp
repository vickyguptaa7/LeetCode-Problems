// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int countNumberswith4(int N) {
        int count=0;
        for(int i=1;i<=N;i++)
        {
            int num=i;
            while(num){
                if(num%10==4){
                    count++;
                    break;
                }
                num/=10;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}  // } Driver Code Ends