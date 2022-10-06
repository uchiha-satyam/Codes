class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int dp1[n+2], dp2[n+2];
        dp1[0] = dp1[1] = 0;
        dp2[0] = dp2[1] = dp2[2] = 0;
        for(int i=2; i<=n; i++)
        {
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i-2]);
        }
        for(int i=3; i<=n+1; i++)
        {
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i-2]);
        }
        return max(dp1[n],dp2[n+1]);
    }
};