//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here
        int n = S.size();
        bool dp[n][n];
        string ans = "";
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                if(i>j)
                {
                    dp[i][j] = false;
                }
                else if(i==j)
                {
                    dp[i][j] = true;
                }
                else
                {
                    if(S[i]==S[j])
                    {
                        if(j-i==1)
                        dp[i][j] = true;
                        else
                        dp[i][j] = dp[i+1][j-1];
                    }
                    else
                    dp[i][j] = false;
                }
                if(dp[i][j]&&ans.length()<=j-i+1)
                ans = S.substr(i,j-i+1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends