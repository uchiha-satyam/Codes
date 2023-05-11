//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        char prev = 'a';
        int n = (s.length()-1)/2;
        int l = s.length();
        for(int i=0; i<=n; i++)
        {
            if(s[i]!='?'||s[l-1-i]!='?')
            {
                prev = (s[i]!='?') ? s[i] : s[l-1-i];
                break;
            }
        }
        int sum = 0;
        for(int i=0; i<=n; i++)
        {
            if(s[i]=='?'&&s[l-1-i]=='?')
            {
                s[i] = prev;
                s[l-1-i] = prev;
            }
            else if(s[i]=='?'||s[l-1-i]=='?')
            {
                if(s[i]=='?') s[i] = s[l-1-i];
                else s[l-1-i] = s[i];
            }
            else
            {
                if(s[i]!=s[l-1-i]) return -1;
            }
            prev = s[i];
            // cout<<s<<endl;
        }
        for(int i=1; i<s.length(); i++)
        {
            sum += abs(s[i]-s[i-1]);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends