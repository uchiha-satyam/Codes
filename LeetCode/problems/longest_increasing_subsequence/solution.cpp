class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int justMin[n];
        for(int i=0; i<n; i++)
        justMin[i] = i;
        int dp[n];
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(justMin[i]==i) dp[i] = 1;
            else dp[i] = 1 + dp[justMin[i]];
            ans = max(ans,dp[i]);
            for(int j=i+1; j<n; j++)
            {
                if(nums[j]>nums[i])
                {
                    if(justMin[j]==j || dp[justMin[j]]<dp[i])
                    {
                        justMin[j] = i;
                    }
                }
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     if(justMin[i]==i) dp[i] = 1;
        //     else dp[i] = 1 + dp[justMin[i]];
        //     ans = max(ans,dp[i]);
        // }
        return ans;
    }
};