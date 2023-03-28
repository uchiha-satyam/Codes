//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int water_flow(vector<vector<int>> &mat,int N,int M){
        vector<vector<pair<bool,bool>>> m(N,vector<pair<bool,bool>>(M,pair<bool,bool>(false,false)));
        for(int j=0; j<M; j++)
        {
            for(int i=0; i<N; i++)
            {
                if(i==0||j==0) m[i][j].first = true;
                if(m[i][j].first)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].first = true;
                    }
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(i==0||j==0) m[i][j].first = true;
                if(m[i][j].first)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].first = true;
                    }
                }
            }
        }
        for(int j=0; j<M; j++)
        {
            for(int i=0; i<N; i++)
            {
                if(i==0||j==0) m[i][j].first = true;
                if(m[i][j].first)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].first = true;
                    }
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(i==0||j==0) m[i][j].first = true;
                if(m[i][j].first)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].first = true;
                    }
                }
            }
        }
        for(int j=M-1; j>=0; j--)
        {
            for(int i=N-1; i>=0; i--)
            {
                if((i==N-1)||(j==M-1)) m[i][j].second = true;
                if(m[i][j].second)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].second = true;
                    }
                }
            }
        }
        
        for(int i=N-1; i>=0; i--)
        {
            for(int j=M-1; j>=0; j--)
            {
                if((i==N-1)||(j==M-1)) m[i][j].second = true;
                if(m[i][j].second)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].second = true;
                    }
                }
            }
        }
        for(int j=M-1; j>=0; j--)
        {
            for(int i=N-1; i>=0; i--)
            {
                if((i==N-1)||(j==M-1)) m[i][j].second = true;
                if(m[i][j].second)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].second = true;
                    }
                }
            }
        }
        
        for(int i=N-1; i>=0; i--)
        {
            for(int j=M-1; j>=0; j--)
            {
                if((i==N-1)||(j==M-1)) m[i][j].second = true;
                if(m[i][j].second)
                {
                    vector<int> mx = {0,1,0,-1};
                    vector<int> my = {1,0,-1,0};
                    for(int k=0; k<4; k++)
                    {
                        int r = i+mx[k];
                        int c = j+my[k];
                        if(r>=N||r<0||c>=M||c<0) continue;
                        if(mat[r][c]>=mat[i][j])
                        m[r][c].second = true;
                    }
                }
            }
        }
        int count = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(m[i][j].first&&m[i][j].second) count++;
            }
        }
        return count;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends