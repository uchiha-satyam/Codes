//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int canRepresentBST(int arr[], int N) {
        // code here
        vector<int> in(N);
        for(int i=0; i<N; i++) in[i] = arr[i];
        sort(in.begin(),in.end());
        unordered_map<int,int> pos;
        for(int i=0; i<N; i++) pos[in[i]] = i;
        stack<pair<int,int>> st;
        st.push({0,N-1});
        int p = 0;
        while(!st.empty())
        {
            pair<int,int> v = st.top();
            st.pop();
            int m = pos[arr[p]];
            p++;
            if(m+1<=v.second) st.push({m+1,v.second});
            if(m-1>=v.first) st.push({v.first,m-1});
            if(m<v.first||m>v.second) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends