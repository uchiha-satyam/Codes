//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int getLeft(int arr[], int l, int r, int& x)
    {
        if(l>r) return INT_MAX;
        int ans = INT_MAX;
        int mid = l + (r-l)/2;
        if(arr[mid]==x) ans = mid;
        if(arr[mid]>=x) return min(ans,getLeft(arr,l,mid-1,x));
        return min(ans,getLeft(arr,mid+1,r,x));
    }
    int getRight(int arr[], int l, int r, int& x)
    {
        if(l>r) return INT_MIN;
        int ans = INT_MIN;
        int mid = l + (r-l)/2;
        if(arr[mid]==x) ans = mid;
        if(arr[mid]>x) return max(ans,getRight(arr,l,mid-1,x));
        return max(ans,getRight(arr,mid+1,r,x));
    }
    /*  if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x) {
        // code here
        int l = getLeft(arr,0,n-1,x);
        int r = getRight(arr,0,n-1,x);
        if(r==INT_MIN) return 0;
        return r - l + 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends