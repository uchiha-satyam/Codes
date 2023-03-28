//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    if(str.length()==0) return 1;
		    if(str[0]=='0') return 0;
		    if(str.find("00")!=string::npos) return 0;
		    int n = str.length();
		    int dp[n+1] = {0};
		    dp[0] = dp[1] = 1;
		    int mod = 1e9 + 7;
		  //  cout<<mod<<endl;
		    for(int i=2; i<=n; i++)
		    {
		        int u = str[i-1]-'0';
		        int t = str[i-2]-'0';
		        int num = 10*t + u;
		      //  cout<<num<<endl;
		        if(u!=0)
		        dp[i] += dp[i-1];
		        if(num<=26&&t!=0)
		        dp[i] += dp[i-2];
		        if(num>26&&u==0)
		        return 0;
		        dp[i] %= mod;
		    }
		    return dp[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends