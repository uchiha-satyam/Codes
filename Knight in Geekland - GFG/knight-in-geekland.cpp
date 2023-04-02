//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        int r = arr.size(), c = arr[0].size();
        vector<int> dp;
        vector<pair<int,int>> movements = {
            {-2, -1},
            {-2, +1},
            {-1, +2},
            {+1, +2},
            {+2, +1},
            {+2, -1},
            {+1, -2},
            {-1, -2}
        };
        queue<pair<int,int>> q;
        q.push(make_pair(start_x,start_y));
        q.push(make_pair(-1,-1));
        dp.push_back(arr[start_x][start_y]);
        int sum = 0;
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        visited[start_x][start_y] = true;
        while(!q.empty())
        {
            int tr = q.front().first;
            int tc = q.front().second;
            q.pop();
            if(tr==-1&&tc==-1)
            {
                dp.push_back(sum);
                if(q.empty()) break;
                q.push(make_pair(tr,tc));
                sum = 0;
                continue;
            }
            // sum += arr[tr][tc];
            // visited[tr][tc] = true;
            for(int i=0; i<8; i++)
            {
                int nr = tr + movements[i].first;
                int nc = tc + movements[i].second;
                if(nr>=0&&nc>=0&&nr<r&&nc<c&&visited[nr][nc]==false)
                {
                    q.push(make_pair(nr,nc));
                    visited[nr][nc] = true;
                    sum += arr[nr][nc];
                }
            }
        }
        int n = dp.size(), mp, m=INT_MIN;
        // for(auto& x : dp)
        // cout<<x<<" ";
        // cout<<endl;
        for(int i=n-1; i>=0; i--)
        {
            if(i+dp[i]<n) dp[i] += dp[i+dp[i]];
            if(dp[i]>=m)
            {
                m = dp[i];
                mp = i;
            }
        }
        // for(auto& x : dp)
        // cout<<x<<" ";
        // cout<<endl;
        return mp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends