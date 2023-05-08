//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int ans = 0, mask = 1;
            while(!s.empty())
            {
                // ans %= m;
                mask %= m;
                if(s.back()-'0')
                {
                    ans += mask;
                }
                mask *= 2;
                s.pop_back();
            }
            return ans%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends