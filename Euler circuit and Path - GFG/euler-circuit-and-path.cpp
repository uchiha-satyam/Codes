//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isEularCircuit(int V, vector<int> adj[]){
	    // Code here
	    int o=0, e=0;
	    for(int i=0; i<V; i++)
	    if(adj[i].size()%2) o++;
	    else e++;
	    if(o==0) return 2;
	    if(o<=2) return 1;
	    return 0;
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
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends