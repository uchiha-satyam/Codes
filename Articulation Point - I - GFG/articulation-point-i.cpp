//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int depth = 0;
    void dfs(int c, int p, vector<int> adj[], vector<int>& dep, vector<int>& mdep, vector<bool>& vis, vector<bool>& art)
    {
        vis[c] = true;
        depth++;
        dep[c] = mdep[c] = depth;
        int cc = 0;
        for(auto& x : adj[c])
        {
            if(x==p) continue;
            if(vis[x]) mdep[c] = min(mdep[c],dep[x]);
            else
            {
                dfs(x,c,adj,dep,mdep,vis,art);
                mdep[c] = min(mdep[c],mdep[x]);
                if(mdep[x]>=dep[c]&&p!=-1)
                art[c] = true;
                cc++;
            }
        }
        if(p==-1&&cc>1) art[c] = true;
    }
    public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> dep(V), mdep(V,INT_MAX);
        vector<bool> vis(V,false), art(V,false);
        dfs(0,-1,adj,dep,mdep,vis,art);
        vector<int> ans;
        for(int i=0; i<V; i++)
        if(art[i]) ans.push_back(i);
        if(ans.empty()) return {-1};
        return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends