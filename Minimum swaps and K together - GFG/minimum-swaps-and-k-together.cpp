//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int ans = INT_MAX, curr = 0;
        for(int i=0; i<n; i++)
        if(arr[i]<=k) curr++;
        ans = curr;
        int l = 0, r = 0;
        while(r<curr)
        {
            if(arr[r]<=k) ans--;
            r++;
        }
        curr = ans;
        while(r<n)
        {
            if(arr[r]<=k) curr--;
            if(arr[l]<=k) curr++;
            l++;
            r++;
            ans = min(ans,curr);
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends