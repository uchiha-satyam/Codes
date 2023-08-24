//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        string s = str;
        reverse(s.begin(),s.end());
        str += "#" + s;
        int n = str.size();
        vector<int> lps(n,0);
        for(int i=1; i<n; i++)
        {
            int j = lps[i-1];
            while(str[i]!=str[j]&&j!=lps[j-1]) j = lps[j-1];
            if(str[i]==str[j]) lps[i] = j+1;
        }
        return n/2 - lps[n-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends