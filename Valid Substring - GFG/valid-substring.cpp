//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int ans = 0, n = s.length();
        int dp[n];
        stack<int> st;
        int lim = -1;
        for(int i=0; i<n; i++)
        {
            dp[i] = 0;
            if(s[i]=='(')
            {
                st.push(i);
                dp[i] = ans;
            }
            else
            {
                if(st.empty())
                {
                    lim = i;
                }
                else
                {
                    st.pop();
                    if(st.empty()) dp[i] = i - lim;
                    else dp[i] = i - st.top();
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends