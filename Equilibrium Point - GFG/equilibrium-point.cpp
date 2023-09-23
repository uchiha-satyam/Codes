//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        // Your code here
        vector<long long> r(n);
        long long sum = 0;
        for(int i=n-1; i>=0; i--)
        {
            r[i] = sum;
            sum += a[i];
        }
        sum = 0;
        int ans = -1;
        for(int i=0; i<n; i++)
        {
            if(sum==r[i])
            {
                ans = i+1;
                break;
            }
            sum += a[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends