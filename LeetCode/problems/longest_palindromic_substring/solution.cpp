class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int m=0;
        int dp[n][n];
        int l=0, r=0;
        for(int j=0; j<n; j++)
        {
            for(int i=n-1; i>=0; i--)
            {
                if(i>j) dp[i][j] = 0;
                else if(i==j) dp[i][j] = 1;
                else if(s[i]==s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                    if(dp[i+1][j-1]==0&&j-i!=1) dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 0;
                }
                if(dp[i][j]>m)
                {
                    l = i;
                    r = j;
                    m = dp[i][j];
                }
            }
        }
        return s.substr(l,r-l+1);
    }
};