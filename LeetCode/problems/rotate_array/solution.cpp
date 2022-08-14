class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int t = nums.size()-(k%nums.size());
        vector<int> vec(nums.size());
        for(int i=t; i<nums.size(); i++)
        {
            vec[i-t] = nums[i];
        }
        for(int i=0; i<t; i++)
        {
            vec[i+(k%nums.size())] = nums[i];
        }
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = vec[i];
        }
    }
};