//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> indeg(N,0);
	    vector<vector<int>> adj(N);
	    for(int i=0; i<P; i++)
	    {
	        indeg[prerequisites[i].second]++;
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    queue<int> q;
	    for(int i=0; i<N; i++)
	    if(indeg[i]==0) q.push(i);
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        for(auto& x : adj[node])
	        {
	            indeg[x]--;
	            if(indeg[x]==0) q.push(x);
	        }
	    }
	    for(int i=0; i<N; i++)
	    if(indeg[i]!=0) return false;
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends