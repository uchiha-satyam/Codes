//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n = A.size(), m = B.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i=1; i<=n; i++)
        {
            if(A[i-1]==C[i-1]) dp[i][0] = true;
            else break;
        }
        for(int i=1; i<=m; i++)
        {
            if(B[i-1]==C[i-1]) dp[0][i] = true;
            else break;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(C[i+j-1]==A[i-1]&&C[i+j-1]==B[j-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(C[i+j-1]==A[i-1])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else if(C[i+j-1]==B[j-1])
                {
                    dp[i][j] = dp[i][j-1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        // for(int i=0; i<=n; i++)
        // {
        //     for(int j=0; j<=m; j++)
        //     cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[n][m];
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends