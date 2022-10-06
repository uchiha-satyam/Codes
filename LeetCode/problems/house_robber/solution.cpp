class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+2];
        dp[0] = dp[1] = 0;
        for(int i=2; i<=n+1; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-2]);
        }
        return dp[n+1];
    }
};