//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> m;
        for(int i=0; i<n; i++) m[arr[i]]++;
        int f1=0, f2=0;
        string s1 = "", s2 = "";
        for(int i=0; i<n; i++)
        {
            int f = m[arr[i]];
            if(f>f1)
            {
                f2 = f1;
                s2 = s1;
                f1 = f;
                s1 = arr[i];
            }
            else if(f>f2&&f<f1)
            {
                f2 = f;
                s2 = arr[i];
            }
        }
        return s2;
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
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends