//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    string exercise(int N, int M, vector<vector<int>> A, int src, int dest, int X){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0; i<M; i++)
        {
            adj[A[i][0]].push_back({A[i][1],A[i][2]});
            adj[A[i][1]].push_back({A[i][0],A[i][2]});
        }
        vector<int> dist(N,INT_MAX);
        vector<bool> vis(N,false);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            int n = pq.top().second;
            pq.pop();
            if(vis[n]) continue;
            vis[n] = true;
            for(auto& x : adj[n])
            {
                if(vis[x.first]||dist[x.first]<=dist[n]+x.second) continue;
                dist[x.first] = dist[n] + x.second;
                pq.push({dist[x.first],x.first});
            }
        }
        if(dist[dest]<=X) return "Neeman's Cotton Classics";
        return "Neeman's Wool Joggers";
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M, src, dest, X;
        cin >> N >> M >> src >> dest >> X;
        vector<vector<int>> A(M, vector<int> (3, 0));
        for(int i = 0; i < M; i++){
            cin >> A[i][0] >> A[i][1] >> A[i][2];
        }
        Solution obj;
        cout << obj.exercise(N, M, A, src, dest, X) << "\n";
    }
}

// } Driver Code Ends