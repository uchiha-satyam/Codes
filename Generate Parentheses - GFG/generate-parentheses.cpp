//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    void help(vector<string>& ans, int o, int c, string s)
    {
        if(o==0&&c==0)
        {
            ans.push_back(s);
            return;
        }
        if(o!=0) help(ans,o-1,c,s+'(');
        if(c!=0&&o<c) help(ans,o,c-1,s+')');
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> ans;
        help(ans,n,n,"");
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends