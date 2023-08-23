//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[n1][n2][n3];
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            for(int k=0; k<n3; k++)
            {
                dp[i][j][k] = 0;
                if(i==0||j==0||k==0)
                {
                    if(A[i]==B[j]&&B[j]==C[k]) dp[i][j][k] = 1;
                    else
                    {
                        if(i>0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
                        if(j>0) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]);
                        if(k>0) dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);
                    }
                    continue;
                }
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
                dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]);
                dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);
                if(A[i]==B[j]&&B[j]==C[k]) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k-1] + 1);
            }
        }
    }
    return dp[n1-1][n2-1][n3-1];
}