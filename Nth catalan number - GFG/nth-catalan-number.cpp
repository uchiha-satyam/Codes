//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long mod = 1e9+7;
vector<long long> fac(1000001);
bool flag = true;

class Solution
{
    public:
    Solution()
    {
        if(flag)
        {
            fac[0] = 1;
            for(int i=1; i<=1000001; i++)
            {
                fac[i] = (fac[i-1]*i)%mod;
            }
            flag = false;
        }
    }
    long long power(long long a, long long b)
    {
        if(a==0||a==1) return a;
        if(b==0) return 1;
        if(b==1) return a;
        long long ans = power(a,b/2);
        ans *= ans;
        ans %= mod;
        if(b%2) ans *= a;
        ans %= mod;
        return ans;
    }
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        long long ans = power(fac[n],mod-2);
        ans *= ans;
        ans %= mod;
        ans *= fac[2*n];
        ans %= mod;
        ans *= power((long long)(n + 1),mod-2);
        ans %= mod;
        return (int)ans;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends