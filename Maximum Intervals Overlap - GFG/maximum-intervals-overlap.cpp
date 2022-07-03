// { Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   sort(Entry,Entry+N);
	   sort(Exit,Exit+N);
	   int mem=0,tme=0;
	   int it1=0,it2=0;
	   int cntr=0;
	   while(it1<N&&it2<N)
	   {
	       if(Entry[it1]<=Exit[it2])
	       {
	           it1++;
	           cntr++;
	       }
	       else
	       {
	           it2++;
	           cntr--;
	       }
	       
	       if(cntr>mem)
	       {
	           mem=cntr;
	           tme=Entry[it1-1];
	       }
	   }
	   return {mem,tme};
	}

};

// { Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends