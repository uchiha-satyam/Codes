//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    void dfs(int n, vector<int> adj[], vector<bool>& vis)
    {
        vis[n] = true;
        for(auto& x : adj[n])
        {
            if(vis[x]) continue;
            dfs(x,adj,vis);
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int> adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    int prev = 0;
	    for(int i=0; i<V; i++)
	    {
	        if(vis[i]) continue;
	        dfs(i,adj,vis);
	        prev = i;
	    }
	    vis = vector<bool>(V,false);
	    dfs(prev,adj,vis);
	    for(int i=0; i<V; i++)
	    if(!vis[i]) return -1;
	    return prev;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends