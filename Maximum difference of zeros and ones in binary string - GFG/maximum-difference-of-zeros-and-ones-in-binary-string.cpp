//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n = S.length();
	    vector<int> v;
	    int sum = 0;
	    for(int i=0; i<n; i++)
	    {
	        if(sum>0&&S[i]=='1')
	        {
	            v.push_back(sum);
	            sum = 0;
	        }
	        else if(sum<0&&S[i]=='0')
	        {
	            v.push_back(sum);
	            sum = 0;
	        }
	        if(S[i]=='0') sum++;
	        else sum--;
	    }
	    v.push_back(sum);
	    sum = 0;
	    int ans = -1;
	    for(int i=0; i<v.size(); i++)
	    {
	        sum += v[i];
	       // cout<<v[i]<<endl;
	        ans = max(ans,sum);
	        if(sum<=0) sum = 0;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends