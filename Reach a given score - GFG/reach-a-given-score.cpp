//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long dp[n+1][3] = {0};
	if(n>=3) dp[3][0] = 1;
	if(n>=5) dp[5][1] = 1;
	if(n>=10) dp[10][2] = 1;
	for(int i=1; i<=n; i++)
	{
	    if(i-3>0)
	    {
	        dp[i][0] += dp[i-3][0];
	    }
	    if(i-5>0)
	    {
	        dp[i][1] += dp[i-5][0] + dp[i-5][1];
	    }
	    if(i-10>0)
	    {
	        dp[i][2] += dp[i-10][0] + dp[i-10][1] + dp[i-10][2];
	    }
	   // cout<<i<<" -> "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	return dp[n][0]+dp[n][1]+dp[n][2];
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends