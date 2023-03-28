//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int mv = arr[0], mp = 0;
        int ans = 1;
        while(mp+mv<n-1)
        {
            if(mv==0) return -1;
            ans++;
            int t = mp+mv;
            int i = mp;
            mv = 0;
            while(i<t)
            {
                i++;
                if(i+arr[i]>=mp+mv)
                {
                    mv = arr[i];
                    mp = i;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends