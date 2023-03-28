//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<bool> dp(leaves+1,true);
        dp[0] = false;
        sort(frogs,frogs+N);
        for(int i=0; i<N; i++)
        {
            int p = frogs[i];
            if(dp[p]==false) continue;
            while(p<=leaves)
            {
                dp[p] = false;
                p += frogs[i];
            }
        }
        int c = 0;
        for(int i=1; i<=leaves; i++)
        if(dp[i]) c++;
        return c;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends