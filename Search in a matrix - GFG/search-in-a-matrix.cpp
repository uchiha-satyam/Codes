//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    // your code here
	    for(int i=0; i<n; i++)
	    {
	        int s=0, e=m-1, mid = s + (e-s)/2;
	        while(s<=e)
	        {
	            mid = s + (e-s)/2;
	            if(mat[i][mid]==x) return 1;
	            else if(mat[i][mid]<x)
	            s = mid+1;
	            else
	            e = mid-1;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends