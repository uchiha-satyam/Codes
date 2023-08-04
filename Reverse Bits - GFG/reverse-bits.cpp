//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        //code here
        string s = bitset<32>(n).to_string();
        reverse(s.begin(),s.end());
        while(s.back()=='0') s.pop_back();
        unsigned int ans = 0;
        int mask = 0;
        for(int i=s.size()-1; i>=0; i--)
        {
            ans += (s[i]-'0')*(1<<mask);
            mask++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    }
    return 0;
}

// } Driver Code Ends