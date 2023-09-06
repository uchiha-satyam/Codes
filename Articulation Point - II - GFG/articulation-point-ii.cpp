//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int depth = 0;
    void traverse(int c, int p, vector<int> adj[], vector<bool>& vis, vector<int>& dep, vector<int>& mdep, vector<int>& ans)
    {
        vis[c] = true;
        depth++;
        dep[c] = mdep[c] = depth;
        int ch = 0;
        bool flag = false;
        for(auto& x : adj[c])
        {
            if(c==p) continue;
            if(vis[x]) mdep[c] = min(mdep[c],dep[x]);
            else
            {
                ch++;
                traverse(x,c,adj,vis,dep,mdep,ans);
                mdep[c] = min(mdep[c],mdep[x]);
                if(mdep[x]>=dep[c]&&p!=-1) flag = true;
            }
        }
        if(flag||(p==-1&&ch>1))
        ans.push_back(c);
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        vector<int> dep(V), mdep(V,INT_MAX), ans;
        for(int i=0; i<V; i++)
        {
            if(vis[i]) continue;
            traverse(i,-1,adj,vis,dep,mdep,ans);
        }
        if(ans.empty()) return {-1};
        sort(ans.begin(),ans.end());
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