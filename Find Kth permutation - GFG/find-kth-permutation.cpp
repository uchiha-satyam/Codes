//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        string s(n,' ');
        vector<int> fac(10);
        fac[0] = fac[1] = 1;
        for(int i=2; i<n; i++) fac[i] = fac[i-1]*i;
        set<int> st;
        for(int i=1; i<=n; i++) st.insert(i);
        k--;
        for(int i=0; i<n; i++)
        {
            int pos = k / fac[n-i-1];
            int val = *next(st.begin(),pos);
            s[i] = '0' + val;
            st.erase(val);
            k = k%fac[n-i-1];
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends