//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(vector<int> adj[], vector<bool>& vis, int s, int& ans, int& d)
    {
        if(s==d)
        {
            ans++;
            return;
        }
        vis[s] = true;
        for(auto& x : adj[s])
        {
            if(vis[x]) continue;
            dfs(adj,vis,x,ans,d);
        }
        vis[s] = false;
    }
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int ans = 0;
        vector<bool> vis(V,false);
        dfs(adj,vis,source,ans,destination);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends