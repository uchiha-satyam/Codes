class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums.back()) return nums.size();
        if(target<nums[0]) return 0;
        int s = 0, e = nums.size()-1;
        int m = s + (e-s)/2;
        while(nums[m]!=target&&s<=e)
        {
            if(nums[m]>target)
            {
                e = m-1;
            }
            else
            {
                s = m+1;
            }
            m = s + (e-s)/2;
        }
        return m;
    }
};