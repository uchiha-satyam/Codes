//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        map<int,int> mp;
        vector<int> dp(n,1);
        for(int i=0; i<n; i++)
        {
            for(auto it = mp.rbegin(); it!=mp.rend(); it++)
            {
                if(it->second<a[i])
                {
                    dp[i] = it->first + 1;
                    break;
                }
            }
            if(mp.count(dp[i]))
            mp[dp[i]] = min(mp[dp[i]],a[i]);
            else
            mp[dp[i]] = a[i];
        }
        return mp.rbegin()->first;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends