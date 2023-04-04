//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        int ans = 0;
        map<int,int> mp;
        for(int i=0; i<N; i++)
        mp[arr[i]]++;
        for(auto it = mp.rbegin(); it!=mp.rend(); ++it)
        {
            if(it->second>1)
            {
                ans += it->second;
                continue;
            }
            for(auto& x : mp)
            {
                if((x.first)>=(it->first)) break;
                if((it->first)%(x.first)==0)
                {
                    ans += it->second;
                    break;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends