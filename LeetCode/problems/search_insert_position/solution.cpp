class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1, mid, pos=-1;
        if(nums[0]>target)
        {
            pos = 0;
            return pos;
        }
        while(s<=e)
        {
            mid = s + (e-s)/2;
            if(nums[mid]==target)
            {
                pos = mid;
                break;
            }
            else if(nums[mid]<target)
            {
                pos = max(pos,mid+1);
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        return pos;
    }
};