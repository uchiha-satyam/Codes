//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
    set<int> st;
    vector<int> dp;
public:
    Solution()
    {
        dp.resize(100001,-1);
    }
    bool help(int n)
    {
        if(n==1) return true;
        if(dp[n]!=-1) return dp[n]==1;
        if(st.count(n))
        {
            dp[n] = 0;
            return false;
        }
        int sum = 0, t = n;
        while(t>0)
        {
            sum += (t%10)*(t%10);
            t /= 10;
        }
        st.insert(n);
        dp[n] = help(sum);
        return dp[n];
    }
    int nextHappy(int N){
        // code here
        for(int i=N+1; i<100001; i++)
        {
            st.clear();
            if(help(i)) return i;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends