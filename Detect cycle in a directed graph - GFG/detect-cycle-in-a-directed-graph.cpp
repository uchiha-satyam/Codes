//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(vector<int> adj[], int v, int c, vector<bool>& v1, vector<bool>& v2)
    {
        v1[c] = true;
        v2[c] = true;
        for(auto& x : adj[c])
        {
            if(v2[x]) return true;
            if(v1[x]) continue;
            if(check(adj,v,x,v1,v2)) return true;
        }
        v2[c] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> v1(V,false), v2(V,false);
        for(int i=0; i<V; i++)
        {
            if(v1[i]) continue;
            if(check(adj,V,i,v1,v2)) return true;
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