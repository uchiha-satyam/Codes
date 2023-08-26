//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        int n = s.size();
        unordered_map<char,int> mp;
        int count = 0;
        int l = 0, r = -1, ans = 0;
        while(r<n-1)
        {
            if(count<=k)
            {
                r++;
                if(!mp.count(s[r])||mp[s[r]]==0) count++;
                mp[s[r]]++;
            }
            else
            {
                mp[s[l]]--;
                if(mp[s[l]]==0) count--;
                l++;
            }
            if(count==k) ans = max(ans,r-l+1);
        }
        if(ans==0) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends