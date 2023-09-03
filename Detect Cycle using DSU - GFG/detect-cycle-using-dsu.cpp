//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int find(vector<int>& par, int x)
    {
        if(x==par[x]) return x;
        return par[x] = find(par,par[x]);
    }
    void merge(vector<int>& par, vector<int>& rank, int x, int y)
    {
        int px = find(par,x);
        int py = find(par,y);
        if(rank[px]<rank[py])
        par[px] = py;
        else if(rank[px]>rank[py])
        par[py] = px;
        else
        {
            par[px] = py;
            rank[py]++;
        }
    }
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> par(V);
        vector<int> rank(V,1);
        for(int i=0; i<V; i++)
        par[i] = i;
        for(int i=0; i<V; i++)
        {
            for(auto& j : adj[i])
            {
                if(j<=i) continue;
                int pi = find(par,i);
                int pj = find(par,j);
                if(pi==pj) return true;
                merge(par,rank,i,j);
            }
        }
        return false;
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
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends