class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int count = 0, maxCount = 0, rest = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                count = 0;
                rest = 0;
                continue;
            }
            if(nums[i]>0)
            {
                count++;
                maxCount = max(maxCount,count);
                continue;
            }
            if(nums[i]<0)
            {
                count++;
                if(rest!=0)
                {
                    count += rest;
                    maxCount = max(maxCount,count);
                    rest = 0;
                    continue;
                }
                rest = count;
                count = 0;
            }
        }
        count = 0;
        rest = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i]==0)
            {
                count = 0;
                rest = 0;
                continue;
            }
            if(nums[i]>0)
            {
                count++;
                maxCount = max(maxCount,count);
                continue;
            }
            if(nums[i]<0)
            {
                count++;
                if(rest!=0)
                {
                    count += rest;
                    maxCount = max(maxCount,count);
                    rest = 0;
                    continue;
                }
                rest = count;
                count = 0;
            }
        }
        return maxCount;
    }
};