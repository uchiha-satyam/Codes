//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    vector<int> dp(n,0);
	    for(int i=1; i<n; i++)
	    {
	        int j = dp[i-1];
	        while(j!=dp[j-1]&&s[i]!=s[j]) j = dp[j-1];
	        if(s[i]==s[j]) dp[i] = j+1;
	    }
	    return dp[n-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends