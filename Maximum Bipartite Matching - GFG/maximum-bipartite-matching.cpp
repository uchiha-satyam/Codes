//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    unordered_map<int,int> match;
    bool possible(int x, vector<vector<int>>& G, vector<int>& start, int& p, int& j)
    {
        int& s = start[x];
        while(s<j)
        {
            if(G[x][s])
            {
                if(!match.count(s) || possible(match[s],G,start,p,j))
                {
                    match[s] = x;
                    s++;
                    return true;
                }
            }
            s++;
        }
        return false;
    }
public:
    int maximumMatch(vector<vector<int>>& G){
        int p = G.size();
        int j = G[0].size();
        int ans = 0;
        vector<int> start(p,0);
        for(int x = 0; x<p; x++)
        {
            if(possible(x,G,start,p,j))
            ans++;
        }
        return ans;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends