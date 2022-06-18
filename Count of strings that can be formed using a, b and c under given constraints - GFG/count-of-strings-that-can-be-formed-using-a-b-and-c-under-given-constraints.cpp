// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    if(n==1)return 3;
    if(n==2)return 8;
    if(n==3)return 19;
    long long result=1;
    result+=n;
    result+=n;
    result+=(n-1)*n;
    result+=((n-1)*n)/2;
    result+=(n-2)*(n-1)*n/2;
    return result;
}