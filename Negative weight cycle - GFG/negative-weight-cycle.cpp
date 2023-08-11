//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(vector<vector<pair<int,int>>>& adj, vector<bool>& v1, vector<bool>& v2, vector<int>& dist, int n, int sum)
    {
        v1[n] = true;
        v2[n] = true;
        dist[n] = sum;
        for(auto& x : adj[n])
        {
            if(v2[x.first])
            {
                if(sum+x.second-dist[x.first]<0) return true;
                if(v1[x.first]) continue;
            }
            if(dfs(adj,v1,v2,dist,x.first,sum+x.second)) return true;
        }
        v2[n] = false;
        return false;
    }
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<vector<pair<int,int>>> adj(n);
	    for(int i=0; i<edges.size(); i++)
	    {
	        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
	    }
	    vector<bool> v1(n,false), v2(n,false);
	    vector<int> dist(n,0);
	    for(int i=0; i<n; i++)
	    {
	        if(v1[i]) continue;
	        if(dfs(adj,v1,v2,dist,i,0)) return true;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends