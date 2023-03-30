//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        map<int,int> m;
        m[arr[n-1]] = n-1;
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i]<arr[i+1])
            {
                auto x = m.upper_bound(arr[i]);
                swap(arr[i],arr[x->second]);
                sort(arr.begin()+i+1,arr.end());
                return arr;
            }
            m[arr[i]] = i;
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends