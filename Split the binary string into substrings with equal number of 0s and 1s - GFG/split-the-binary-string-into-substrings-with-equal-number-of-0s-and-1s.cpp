//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int c = 0, ans = 0;
        int n = str.size();
        for(int i=0; i<n; i++)
        {
            if(str[i]=='0') c--;
            else c++;
            if(c==0) ans++;
        }
        if(c==0) return ans;
        return -1;
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
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends