class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int mid;
        int pos = -1;
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