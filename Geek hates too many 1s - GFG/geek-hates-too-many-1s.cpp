//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        if(n==0) return n;
        string  bit = "";
        while(n>0)
        {
            bit = (char)((n%2) + '0') + bit;
            n/=2;
        }
        // cout<<bit<<endl;
        int c = 0;
        for(auto& x : bit)
        {
            if(x=='1')
            {
                c++;
                if(c==3)
                {
                    x = '0';
                    c = 0;
                }
            }
            else c = 0;
        }
        int num = 0, mask = 1;
        for(int i=bit.size()-1; i>=0; i--)
        {
            num += mask * (bit[i]-'0');
            mask *= 2;
        }
        return num;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends