//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        int rs=0, cs=0, re=r-1, ce=c-1;
        vector<int> ans(r*c);
        int pos = 0;
        while(pos<r*c)
        {
            for(int i=cs; i<=ce; i++)
            {
                ans[pos] = matrix[rs][i];
                pos++;
            }
            rs++;
            if(pos>=r*c) break;
            for(int i=rs; i<=re; i++)
            {
                ans[pos] = matrix[i][ce];
                pos++;
            }
            ce--;
            if(pos>=r*c) break;
            for(int i=ce; i>=cs; i--)
            {
                ans[pos] = matrix[re][i];
                pos++;
            }
            re--;
            if(pos>=r*c) break;
            for(int i=re; i>=rs; i--)
            {
                ans[pos] = matrix[i][cs];
                pos++;
            }
            cs++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends