//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<pair<char,pair<int,int>>> moves;
    public:
    Solution()
    {
        moves = {
            {'U',{-1,0}},
            {'D',{1,0}},
            {'L',{0,-1}},
            {'R',{0,1}}
        };
    }
    void traverse(vector<vector<int>>& m, vector<vector<bool>>& vis, vector<string>& ans, string& str,int x, int y, int& n, char ch)
    {
        vis[x][y] = true;
        if(ch!='F') str.push_back(ch);
        if(x==n-1&&y==n-1)
        {
            ans.push_back(str);
            str.pop_back();
            vis[x][y] = false;
            return;
        }
        for(int i=0; i<4; i++)
        {
            int nx = x + moves[i].second.first;
            int ny = y + moves[i].second.second;
            if(nx<0||ny<0||nx>=n||ny>=n||!m[nx][ny]||vis[nx][ny]) continue;
            traverse(m,vis,ans,str,nx,ny,n,moves[i].first);
        }
        str.pop_back();
        vis[x][y] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string str = "";
        if(!m[0][0]||!m[n-1][n-1]) return ans;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        traverse(m,vis,ans,str,0,0,n,'F');
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends