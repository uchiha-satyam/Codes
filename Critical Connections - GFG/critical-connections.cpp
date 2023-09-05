//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int depth;
    void dfs(int c, int p, vector<int> adj[], vector<int>& dep, vector<int>& mdep, vector<bool>& vis, vector<vector<int>>& ans)
    {
        vis[c] = true;
        depth++;
        dep[c] = mdep[c] = depth;
        for(auto& x : adj[c])
        {
            if(x==p) continue;
            if(!vis[x])
            {
                dfs(x,c,adj,dep,mdep,vis,ans);
                if(mdep[x]>dep[c]) ans.push_back({min(c,x),max(c,x)});
            }
            mdep[c] = min(mdep[c],mdep[x]);
        }
    }
public:
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> ans;
	    vector<int> dep(V), mdep(V,INT_MAX);
	    vector<bool> vis(V,false);
	    dfs(0,-1,adj,dep,mdep,vis,ans);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
    Solution()
    {
        depth = 0;
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends