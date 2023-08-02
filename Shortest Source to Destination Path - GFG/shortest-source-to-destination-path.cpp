//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0||A[X][Y]==0) return -1;
        map<pair<int,int>,vector<pair<int,int>>> mp;
        set<pair<int,int>> visited;
        map<pair<int,int>,int> dist;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(A[i][j])
                {
                    dist[make_pair(i,j)] = INT_MAX;
                    if(i-1>=0&&A[i-1][j]) mp[make_pair(i,j)].push_back(make_pair(i-1,j));
                    if(i+1<N&&A[i+1][j]) mp[make_pair(i,j)].push_back(make_pair(i+1,j));
                    if(j-1>=0&&A[i][j-1]) mp[make_pair(i,j)].push_back(make_pair(i,j-1));
                    if(j+1<M&&A[i][j+1]) mp[make_pair(i,j)].push_back(make_pair(i,j+1));
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[make_pair(0,0)] = 0;
        pq.push(make_pair(0,make_pair(0,0)));
        while(!pq.empty())
        {
            pair<int,int> node = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            if(visited.count(node)) continue;
            visited.insert(node);
            for(auto& x : mp[node])
            {
                if(val+1<dist[x])
                {
                    dist[x] = val+1;
                    pq.push(make_pair(dist[x],x));
                }
            }
        }
        return (dist[make_pair(X,Y)]!=INT_MAX) ? dist[make_pair(X,Y)] : -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends