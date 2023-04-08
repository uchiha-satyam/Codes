//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		bool dp[N+1] = {false};
		dp[1] = true;
		if(X<=N) dp[X] = true;
		if(Y<=N) dp[Y] = true;
		for(int i=2; i<=N; i++)
		{
		    bool b = dp[i-1];
		    if(i>=X) b = b&&dp[i-X];
		    if(i>=Y) b = b&&dp[i-Y];
		    if(b) dp[i] = false;
		    else dp[i] = true;
		}
// 		for(int i=0; i<=N; i++)
// 		cout<<dp[i]<<" ";
// 		cout<<endl;
		return dp[N];
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends