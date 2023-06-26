//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod = 1e9+7;
class Solution{
    vector<int> fac;
public:
    Solution()
    {
        fac.resize(1001);
        fac[0] = 1;
        for(int i=1; i<1001; i++)
        {
            long long p = fac[i-1] * 1LL * i;
            p %= mod;
            fac[i] = p;
        }
    }
    int power(int b, int p)
    {
        if(p == 1 || b == 1)
        {
            return b;
        }
        else if(p%2 == 0)
        {
            long long lwd = power(b,p/2);
            lwd *= lwd;
            lwd %= mod;
            return lwd;
        }
        else
        {
            long long lwd = power(b,p/2);
            lwd *= lwd;
            lwd %= mod;
            lwd *= b;
            lwd %= mod;
            return lwd;
        }
        return 1;
    }
    int nCr(int n, int r){
        // code here
        // for(int i=0; i<=25; i++)
        // {
        //     cout<<fac[i]<<" ";
        // }
        if(r>n)
        {
            return 0;
        }
        long long nu = fac[n];
        long long de = fac[n-r] * 1LL * fac[r];
        de %= mod;
        de = power(de, mod-2);
        long long p = nu * de;
        p %= mod;
        return p;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends