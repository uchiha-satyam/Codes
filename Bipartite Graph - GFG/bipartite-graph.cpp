//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    unordered_map<int,int> grp;
	    vector<bool> visited(V,false);
	    int val = 1;
	    for(int i=0; i<V; i++)
	    {
	        if(visited[i]) continue;
    	    grp[i] = val;
    	    queue<int> q;
    	    q.push(i);
    	    while(!q.empty())
    	    {
    	        int node = q.front();
    	        q.pop();
    	        if(visited[node]) continue;
    	        visited[node] = true;
    	        int g = grp[node];
    	        for(auto& x : adj[node])
    	        {
    	            if(grp.count(x)&&grp[x]==g) return false;
    	            grp[x] = -1*g;
    	            if(!visited[x]) q.push(x);
    	        }
    	    }
    	    val++;
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends