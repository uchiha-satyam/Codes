//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> vis(1e5,0);
        int c = 1;
        queue<int> q;
        q.push(start);
        q.push(-1);
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            if(n==-1)
            {
                if(q.empty()) break;
                c++;
                q.push(-1);
                continue;
            }
            if(vis[n]) continue;
            vis[n] = c;
            for(auto& x : arr)
            {
                int p = ((long long)n * x)%((long long)1e5);
                if(vis[p]) continue;
                q.push(p);
            }
        }
        if(vis[end]) return vis[end]-1;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends