//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int mod = 1e9+7;
        int dp[n][sum+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(i==0)
                {
                    if(j==arr[i]) dp[i][j] += 1;
                    continue;
                }
                dp[i][j] += dp[i-1][j];
                if(j>=arr[i]) dp[i][j] += dp[i-1][j-arr[i]];
                dp[i][j] = dp[i][j]%mod;
            }
        }
        return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends