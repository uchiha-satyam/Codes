//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans = "";
        int j = 0;
        int f = 1;
        while(true)
        {
            char c = arr[0][j];
            for(int i=0; i<N; i++)
            {
                if(arr[i].length()<j||arr[i][j]!=c)
                {
                    f = 0;
                    break;
                }
            }
            if(f==0) break;
            ans += c;
            j++;
        }
        if(ans=="") ans = "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends