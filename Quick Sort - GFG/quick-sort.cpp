//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)
            return;
        
        int partitionIndx=partition(arr,low,high);
        quickSort(arr,low,partitionIndx-1);
        quickSort(arr,partitionIndx+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int indx=(rand()%(high-low))+low;
        swap(arr[indx],arr[low]);
        int prev=low,next=high;
        
        for(int i=low;i<=high&&i<=next;i++)
        {
            if(arr[i]==arr[prev])
            {
                continue;
            }
            else if(arr[i]<arr[prev])
            {
                swap(arr[prev],arr[i]);
                prev++;
            }
            else
            {
                swap(arr[next],arr[i]);
                i--;
                next--;
            }
        }
        return prev;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends