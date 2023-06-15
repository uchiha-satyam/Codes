//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    void help(int& l, int& r, int x, int sum, int& d, vector<int>& v)
    {
        if(x>r) return;
        if(x<=r&&x>=l) v.push_back(x);
        int digits = 0;
        if(x!=0) digits = (int)log10(x);
        for(int i=sum+1; i<=9; i++)
        {
            if(i==d) continue;
            help(l,r,i*pow(10,digits+1)+x,sum+i,d,v);
        }
    }
  public:
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int> ans;
        for(int i=0; i<=9; i++)
        {
            if(i==D) continue;
            help(L,R,i,i,D,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends