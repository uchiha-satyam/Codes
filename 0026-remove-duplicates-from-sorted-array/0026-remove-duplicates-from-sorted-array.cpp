class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 1;
        while(p<nums.size())
        {
            if(nums[p]==nums[p-1])
            {
                nums.erase(nums.begin()+p);
            }
            else p++;
        }
        return nums.size();
    }
};