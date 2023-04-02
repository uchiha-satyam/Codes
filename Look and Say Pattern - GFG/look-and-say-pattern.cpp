//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        vector<string> dp(n,"");
        dp[0] = "1";
        for(int i=1; i<n; i++)
        {
            string& s = dp[i-1];
            char prev = s[0];
            int c = 1;
            for(int j=1; j<s.length(); j++)
            {
                if(s[j]==prev)
                {
                    c++;
                }
                else
                {
                    dp[i] += to_string(c) + prev;
                    prev = s[j];
                    c = 1;
                }
            }
            dp[i] += to_string(c) + prev;
        }
        return dp[n-1];
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends