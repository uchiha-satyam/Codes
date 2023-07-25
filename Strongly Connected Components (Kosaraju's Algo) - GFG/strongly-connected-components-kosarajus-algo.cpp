//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st, int curr, vector<vector<int>>& adjT)
	{
	    if(visited[curr]) return;
	    visited[curr] = true;
	    for(auto& n : adj[curr])
	    {
	        adjT[n].push_back(curr);
	        dfs(adj,visited,st,n,adjT);
	    }
	    st.push(curr);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st, temp;
        vector<bool> visited(V,false);
        vector<vector<int>> adjT(V);
        for(int i=0; i<V; i++)
        {
            if(visited[i]) continue;
            dfs(adj,visited,st,i,adjT);
        }
        visited = vector<bool>(V,false);
        int c = 0;
        while(!st.empty())
        {
            int n = st.top();
            st.pop();
            if(visited[n]) continue;
            c++;
            dfs(adjT,visited,temp,n,adj);
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends