class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int data[10002] = {0}, dp[10003];
        dp[0] = dp[1] = 0;
        for(int i=0; i<n; i++)
        {
            data[nums[i]]++;
        }
        for(int i=2; i<=10002; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+(i-1)*data[i-1]);
        }
        return dp[10002];
    }
};