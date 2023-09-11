//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long printDivisors(long long n)
    {
        // Note that this loop runs till square root
        long long ans = 1;
        for (long long i=2; i<=sqrt(n); i++)
        {
            if (n%i == 0)
            {
                // If divisors are equal, print only one
                if (n/i == i)
                    ans += i;
      
                else // Otherwise print both
                    ans += i + n/i;
            }
        }
        return ans;
    }
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N!=1&&N==printDivisors(N)) return true;
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends