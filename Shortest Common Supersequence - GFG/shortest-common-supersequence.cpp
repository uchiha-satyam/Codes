//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<pair<string,int>>> dp(m+1,vector<pair<string,int>>(n+1));
        for(int i=0; i<=m; i++)
        dp[i][0] = {X.substr(0,i),0};
        for(int j=0; j<=n; j++)
        dp[0][j] = {Y.substr(0,j),0};
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dp[i][j] = {dp[i-1][j].first + X[i-1],dp[i-1][j].second};
                if(dp[i][j].second<dp[i][j-1].second)
                dp[i][j] = {dp[i][j-1].first + Y[j-1],dp[i][j-1].second};
                if(X[i-1]==Y[j-1]&&dp[i][j].second<dp[i-1][j-1].second+1)
                dp[i][j] = {dp[i-1][j-1].first + X[i-1],dp[i-1][j-1].second + 1};
                // cout<<dp[i][j].second<<"\t";
            }
            // cout<<endl;
        }
        // cout<<dp[m][n].first<<" "<<dp[m][n].second;
        return dp[m][n].first.size();
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends