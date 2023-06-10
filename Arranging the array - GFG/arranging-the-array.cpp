//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            int p1=0, p2=0;
            int temp[n];
            for(int i=0; i<n; i++)
            {
                temp[i] = arr[i];
                if(arr[i]<0) p2++;
            }
            for(int i=0; i<n; i++)
            {
                if(temp[i]<0)
                {
                    arr[p1] = temp[i];
                    p1++;
                }
                else
                {
                    arr[p2] = temp[i];
                    p2++;
                }
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends