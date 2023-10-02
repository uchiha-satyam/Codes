//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
    int distinctSubsequences(string s)
    {
        // Your code goes here
        int mod = 1e9 + 7;
        int n = s.size();
        unordered_map<char,int> mp;
        int dp[n][2];
        dp[0][0] = dp[0][1] = 1;
        mp[s[0]] = 0;
        for(int i=1; i<n; i++)
        {
            dp[i][0] = dp[i][1] = dp[i-1][0] + dp[i-1][1];
            dp[i][0] %= mod;
            dp[i][1] %= mod;
            if(mp.count(s[i]))
            dp[i][0] = (dp[i][1] - dp[mp[s[i]]][1] + mod) % mod;
            mp[s[i]] = i;
        }
        return (dp[n-1][0] + dp[n-1][1])%mod;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends