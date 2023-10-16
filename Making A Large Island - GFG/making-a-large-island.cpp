//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int bfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int r,int c,vector<pair<int,int>> &s,vector<vector<int>> &m,int val){
        int r1[4]={1,0,-1,0};
        int c1[4]={0,1,0,-1};
        int count=0,n=grid.size();
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            visited[r][c]=1;
            m[r][c]=val;
            s.push_back({r,c});
            ++count;
            for(int i=0;i<4;++i){
                int new_r=r+r1[i],new_c=c+c1[i];
                if(new_r>=0&&new_r<n&&new_c>=0&&new_c<n&&visited[new_r][new_c]==0&&grid[new_r][new_c]==1){
                    q.push({new_r,new_c});
                    visited[new_r][new_c]=1;
                }
            }
        }
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size(),ans=INT_MIN,val=0;
        vector<vector<int>> m(n,vector<int>(n,-1));
        if(n==0)
        return 0;
        vector<vector<int>> v(n,vector<int>(n,0));
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(visited[i][j]==0&&grid[i][j]==1){
                    vector<pair<int,int>> s;
                    int count=bfs(grid,visited,i,j,s,m,val);
                    ++val;
                    if(ans<count)
                    ans=count;
                    for(int i=0;i<s.size();++i){
                        pair<int,int> p=s[i];
                        int r=p.first,c=p.second;
                        v[r][c]=count;
                    }
                }
            }
        }
        int curr=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    set<int> s1;
                    curr=0;
                int r1[4]={1,0,-1,0};
                int c1[4]={0,1,0,-1};
                for(int k=0;k<4;++k){
                    int new_r=i+r1[k],new_c=j+c1[k];
                     if(new_r>=0&&new_r<n&&new_c>=0&&new_c<n){
                         if(s1.size()==0||s1.find(m[new_r][new_c])==s1.end())
                         curr+=(v[new_r][new_c]);
                         s1.insert(m[new_r][new_c]);
                     }
                }
                ++curr;
                if(curr>ans)
                ans=curr;
            }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends