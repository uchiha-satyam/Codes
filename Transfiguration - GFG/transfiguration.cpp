//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	int ans = 0, n = A.size();
    	unordered_map<char,int> mp;
    	int p1 = n-1, p2 = n-1;
    	while(p1>=0)
    	{
    	    if(A[p1]==B[p2]) p2--;
    	    else
    	    {
    	        mp[A[p1]]++;
    	        ans++;
    	    }
    	    p1--;
    	}
    	while(p2>=0)
    	{
    	    mp[B[p2]]--;
    	    if(mp[B[p2]]<0) return -1;
    	    p2--;
    	}
    	return ans;
    }
};

//{ Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}
// } Driver Code Ends