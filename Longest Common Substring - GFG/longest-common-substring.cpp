//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n][m];
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dp[i][j] = 0;
                if(S1[i]==S2[j])
                {
                    if(i==0||j==0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j-1] + 1;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends