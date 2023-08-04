//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int c = 0;
        while(b>0)
        {
            c += b%2;
            b /= 2;
        }
        int ans = 0;
        int mask = 31;
        int arr[32] = {0};
        while(mask>=0&&c>0)
        {
            if(a&(1<<mask))
            {
                c--;
                arr[mask] = 1;
            }
            mask--;
        }
        for(int i=0; i<32; i++)
        {
            // cout<<arr[i]<<" ";
            if(c!=0&&arr[i]!=1)
            {
                arr[i] = 1;
                c--;
            }
            ans += arr[i]*(1<<i);
        }
        if(c==0) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends