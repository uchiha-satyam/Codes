class Solution {
public:

    // int c(string& s, int i)
    // {
    //     if(i>s.size()||s[i]=='0') return 0;
    //     if(i==s.size() || i+1==s.size()) return 1;
    //     int c1 = s[i] - '0';
    //     int c2 = s[i+1] - '0';
    //     if(c1>2||(c1==2 && c2>6)) return c(s,i+1);
    //     if(c2==0) return c(s,i+2);
    //     return c(s,i+1) + c(s,i+2);
    // }

    int numDecodings(string s) {
        int n = s.size();
        int dp[n+2];
        dp[n+1] = 0;
        dp[n] = 1;
        for(int i=n-1; i>=0; i--)
        {
            int c1 = s[i] - '0';
            if(c1==0)
            {
                dp[i] = 0;
                continue;
            }
            int c2;
            if(i==n-1) c2 = 1;
            else c2 = s[i+1] - '0';
            if(c1>2 || (c1==2 && c2>6))
            {
                dp[i] = dp[i+1];
                continue;
            }
            if(c2==0)
            {
                dp[i] = dp[i+2];
                continue;
            }
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
        // return c(s,0);
    }
};