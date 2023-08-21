//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        int desired = (R*C+1)/2;
        int left = 1, right = 2000;
        int ans;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            int count = 0;
            for(int i=0; i<R; i++)
            {
                int l = 0, r = C-1;
                while(l<=r)
                {
                    int m = l + (r-l)/2;
                    if(matrix[i][m]<=mid) l = m + 1;
                    else r = m - 1;
                }
                // cout<<i<<"->"<<l<<" ";
                count += l;
            }
            // cout<<mid<<" "<<count<<endl;
            if(count>=desired)
            {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends