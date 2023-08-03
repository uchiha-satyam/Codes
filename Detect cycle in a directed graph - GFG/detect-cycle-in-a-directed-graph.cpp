//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    bool dfs(vector<int> adj[], vector<bool>& univ, vector<bool>& local, int n)
    {
        univ[n] = true;
        local[n] = true;
        for(auto& x : adj[n])
        {
            if(local[x]) return true;
            if(univ[x]) continue;
            if(dfs(adj,univ,local,x)) return true;
        }
        local[n] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> univ(V,false), local(V,false);
        for(int i=0; i<V; i++)
        {
            if(univ[i]) continue;
            if(dfs(adj,univ,local,i)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends