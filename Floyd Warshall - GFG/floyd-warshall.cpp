//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>& matrix){
	    // Code here
	    int n = matrix.size();
	    vector<vector<int>> ans(n,vector<int>(n,INT_MAX));
	    for(int i=0; i<n; i++)
	    {
	        vector<bool> visited(n,false);
	        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	        ans[i][i] = 0;
	        pq.push({0,i});
	        while(!pq.empty())
	        {
	            int node = pq.top().second;
	            int val = pq.top().first;
	            pq.pop();
	            if(visited[node]) continue;
	            visited[node] = true;
	            for(int j=0; j<n; j++)
	            {
	                if(matrix[node][j]==0||matrix[node][j]==-1||visited[j]) continue;
	                if(val+matrix[node][j]<ans[i][j])
	                {
	                    ans[i][j] = val+matrix[node][j];
	                    pq.push({ans[i][j],j});
	                }
	            }
	        }
	    }
	    for(int i=0; i<n; i++)
	    for(int j=0; j<n; j++)
        matrix[i][j] = (ans[i][j]==INT_MAX) ? -1 : ans[i][j];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends