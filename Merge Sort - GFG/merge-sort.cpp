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
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int temp[r-l+1];
        int p = 0, p1 = l, p2 = m+1;
        while(p1<=m||p2<=r)
        {
            if((p1<=m&&p2<=r&&arr[p1]<arr[p2])||(p2>r))
            {
                temp[p] = arr[p1];
                p1++;
            }
            else
            {
                temp[p] = arr[p2];
                p2++;
            }
            p++;
        }
        for(int i=l; i<=r; i++)
        arr[i] = temp[i-l];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(r<=l) return;
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends