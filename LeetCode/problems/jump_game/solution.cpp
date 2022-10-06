class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int steps = 1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]>=steps)
            {
                flag = true;
                steps = 1;
            }
            else
            {
                flag = false;
                steps++;
            }
        }
        return flag;
    }
};