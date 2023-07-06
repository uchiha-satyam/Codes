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
        // code here
        if(low>=high) return;
        int p = partition(arr,low,high);
        quickSort(arr,low,p);
        quickSort(arr,p+1,high);
        int temp[high-low+1];
        int p1=low, p2=p+1;
        int pos=0;
        while(pos<high-low+1)
        {
            if(p1<=p&&p2<=high)
            {
                if(arr[p1]<arr[p2])
                {
                    temp[pos] = arr[p1];
                    p1++;
                }
                else
                {
                    temp[pos] = arr[p2];
                    p2++;
                }
            }
            else if(p1<=p)
            {
                temp[pos] = arr[p1];
                p1++;
            }
            else
            {
                temp[pos] = arr[p2];
                p2++;
            }
            pos++;
        }
        pos = 0;
        while(pos<high-low+1)
        {
            arr[low+pos] = temp[pos];
            pos++;
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int p = low + (high-low)/2;
       return p;
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