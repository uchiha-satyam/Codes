//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int n, stack<int>& st, vector<vector<int>>& newAdj)
    {
        visited[n] = true;
        for(auto& x : adj[n])
        {
            newAdj[x].push_back(n);
            if(visited[x]) continue;
            dfs(adj,visited,x,st,newAdj);
        }
        st.push(n);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st, temp;
        vector<vector<int>> newAdj(V);
        vector<bool> visited(V,false);
        for(int i=0; i<V; i++)
        {
            if(visited[i]) continue;
            dfs(adj,visited,i,st,newAdj);
        }
        int ans = 0;
        visited = vector<bool>(V,false);
        while(!st.empty())
        {
            int n = st.top();
            st.pop();
            if(visited[n]) continue;
            ans++;
            dfs(newAdj,visited,n,temp,adj);
        }
        return ans;
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