//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(vector<int> adj[], vector<bool>& visited, int n)
    {
        visited[n] = true;
        for(auto& x : adj[n])
        {
            if(visited[x]) continue;
            dfs(adj,visited,x);
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        int prevc = 0, currc = 0;
        vector<bool> visited(V,false);
        for(int i=0; i<V; i++)
        {
            if(visited[i]) continue;
            prevc++;
            dfs(adj,visited,i);
        }
        for(auto& x : adj[c])
        if(x==d) x = c;
        for(auto& x : adj[d])
        if(x==c) x = d;
        visited = vector<bool>(V,false);
        for(int i=0; i<V; i++)
        {
            if(visited[i]) continue;
            currc++;
            dfs(adj,visited,i);
        }
        if(currc!=prevc) return true;
        return false;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends