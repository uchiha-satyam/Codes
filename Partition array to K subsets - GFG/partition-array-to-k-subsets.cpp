//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
    bool check(vector<string>& v, int& size, int& k, int count, string x, int idx)
    {
        if(count==k)
        {
            for(auto& ch : x)
            if(ch!='1') return false;
            return true;
        }
        if(count>k||idx>=size) return false;
        count++;
        int n = x.size();
        for(int i=idx; i<size; i++)
        {
            string nx(n,'0');
            bool flag = true;
            for(int j=0; j<n; j++)
            {
                nx[j] = '0' + (x[j]-'0') + (v[i][j]-'0');
                if(nx[j]>'1')
                {
                    flag = false;
                    break;
                }
            }
            if(flag&&check(v,size,k,count,nx,i+1)) return true;
        }
        return false;
    }
public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        //Your code here
        int sum = 0;
        for(int i=0; i<n; i++) sum += a[i];
        if(sum%k) return false;
        sum /= k;
        for(int i=0; i<n; i++)
        if(a[i]>sum) return false;
        vector<vector<vector<string>>> dp(n,vector<vector<string>>(sum+1));
        for(int j=0; j<=sum; j++)
        {
            for(int i=0; i<n; i++)
            {
                if(j==0)
                {
                    string x(n,'0');
                    dp[i][j].push_back(x);
                    continue;
                }
                if(j==a[i])
                {
                    string x(n,'0');
                    x[i] = '1';
                    dp[i][j].push_back(x);
                }
                if(i>0)
                {
                    for(auto& x : dp[i-1][j])
                    dp[i][j].push_back(x);
                    if(j>a[i])
                    {
                        for(auto x : dp[i-1][j-a[i]])
                        {
                            x[i] = '1';
                            dp[i][j].push_back(x);
                        }
                    }
                }
            }
        }
        vector<string>& v = dp[n-1][sum];
        int size = v.size();
        string x(n,'0');
        if(check(v,size,k,0,x,0)) return true;
        return false;
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends