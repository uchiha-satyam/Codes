class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int check = 0, pos = 0, length = 1;
        for(int i=1; i<n; i++)
        {
            if(nums[i]>nums[pos] && (check==1 || check==0))
            {
                length++;
                check = -1;
            }
            else if(nums[i]<nums[pos] && (check==-1 || check==0))
            {
                length++;
                check = 1;
            }
            pos = i;
        }
        return length;
    }
};