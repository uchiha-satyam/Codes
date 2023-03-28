//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> o;
        int l=n;
        for(int i=0; i<n; i++)
        {
            o[arr[i]]++;
        }
        int ans = 0;
        vector<long long> dp(l+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=l; i++)
        {
            dp[i] = dp[i-1] * i;
        }
        for(int i=0; i<n; i++)
        {
            if(!o.count(arr[i])) continue;
            int res = k - arr[i];
            if(res>arr[i])
            {
                ans += o[res]*o[arr[i]];
                o.erase(res);
                o.erase(arr[i]);
            }
            else if(res==arr[i])
            {
                ans += dp[o[res]]/(dp[o[res]-2]*dp[2]);
                o.erase(res);
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends