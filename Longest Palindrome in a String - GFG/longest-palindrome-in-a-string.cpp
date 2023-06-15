//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        string ans = "";
        int c = 0;
        int n = S.length();
        for(int i=0; i<n; i++)
        {
            int l=i-1, r=i+1, tc=1;
            while(l>=0&&r<n&&S[l]==S[r])
            {
                tc += 2;
                l--;
                r++;
            }
            if(tc>c)
            {
                c = tc;
                ans = S.substr(l+1,tc);
            }
        }
        for(int i=0; i<n; i++)
        {
            int l=i, r=i+1, tc=0;
            while(l>=0&&r<n&&S[l]==S[r])
            {
                tc += 2;
                l--;
                r++;
            }
            if(tc>c)
            {
                c = tc;
                ans = S.substr(l+1,tc);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends