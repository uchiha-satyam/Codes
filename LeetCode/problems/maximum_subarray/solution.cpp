class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int temp = sum;
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0)
            {
                if(temp!=0)
                maxSum = max(maxSum,temp);
                sum = 0;
            }
        }
        return maxSum;
    }
};