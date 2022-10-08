class Solution {
public:
    int maxSubarraySumCircular(vector<int> nums) {
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN, minSum = INT_MAX;
        // for(int i=0; i<n; i++)
        // nums.push_back(nums[i]);
        // int pos1 = n-1, pos2 = 0;
        // while(pos1>0)
        // {
        //     if(nums[pos1]<0) break;
        //     pos1--;
        // }
        // if(pos1==-1) pos1 = 0;
        // while(pos2<n)
        // {
        //     if(nums[pos2]<0) break;
        //     pos2++;
        // }
        // if(pos2==n) pos2 = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0)
            {
                sum = 0;
            }
        }
        sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            minSum = min(minSum,sum);
            if(sum>0)
            {
                sum = 0;
            }
        }
        sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        // sum = 0;
        // for(int i=0; i<n; i++)
        // {
        //     sum += nums[(i+pos2)%n];
        //     maxSum = max(maxSum,sum);
        //     if(sum<0)
        //     {
        //         sum = 0;
        //     }
        // }
        if(minSum==sum) return maxSum;
        return max(maxSum,sum-minSum);
    }
};