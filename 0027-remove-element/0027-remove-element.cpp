class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0, r=nums.size()-1;
        while(l<=r)
        {
            if(nums[r]==val)
            {
                r--;
                continue;
            }
            if(nums[l]==val)
            {
                swap(nums[l],nums[r]);
                r--;
            }
            l++;
        }
        return r+1;
    }
};