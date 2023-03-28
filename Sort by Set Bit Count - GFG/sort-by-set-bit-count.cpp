//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    int nob(int x)
    {
        int ans = 0;
        while(x>0)
        {
            ans += x%2;
            x /= 2;
        }
        return ans;
    }
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        map<int,vector<int>,greater<int>> m;
        for(int i=0; i<n; i++)
        {
            m[nob(arr[i])].push_back(arr[i]);
        }
        int p=0;
        for(auto& x : m)
        {
            for(auto& e : x.second)
            {
                arr[p] = e;
                p++;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends