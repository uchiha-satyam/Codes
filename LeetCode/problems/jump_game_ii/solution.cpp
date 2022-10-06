class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        cout<<"n : "<<n<<endl;
        int dp[n];
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--)
        {
            int m = INT_MAX-1;
            for(int j=1; j<=nums[i] && i+j<=n-1; j++)
            {
                m = min(m,dp[i+j]);
            }
            cout<<m<<" "<<i<<endl;
            dp[i] = m+1;
        }
        return dp[0];
    }
};