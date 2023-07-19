//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n = A.length();
        vector<int> *prev = new vector<int>(n,0), *curr = new vector<int>(n,0);
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j) (*curr)[j] = 1;
                else
                {
                    (*curr)[j] = max((*curr)[j-1],(*prev)[j]);
                    if(A[i]==A[j])
                    (*curr)[j] = max((*curr)[j],(*prev)[j-1]+2);
                }
            }
            swap(curr,prev);
        }
        return (*prev)[n-1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends