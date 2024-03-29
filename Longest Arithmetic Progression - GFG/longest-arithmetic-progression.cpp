//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        int ans = 1;
        vector<vector<int>> dp(n,vector<int>(10000,0));
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int diff = A[j]-A[i];
                if(dp[j][diff]==0) dp[j][diff] = 2;
                if(dp[i][diff]) dp[j][diff] = max(dp[j][diff],dp[i][diff] + 1);
                ans = max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends