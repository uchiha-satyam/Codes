//{ Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    cpp_int c(vector<cpp_int>& dp, int n, int r)
    {
        return dp[n]/(dp[n-r]*dp[r]);
    }
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        vector<cpp_int> dp(2*n+1,0);
        dp[0] = 1;
        for(int i=1; i<=2*n; i++)
        dp[i] = dp[i-1]*i;
        cpp_int ans = c(dp,2*n,n)/(n+1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends