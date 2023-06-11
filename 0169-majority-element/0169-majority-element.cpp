class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int p=nums[0], c=1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]==p) c++;
            else c--;
            if(c==0)
            {
                p = nums[i];
                c++;
            }
        }
        return p;
    }
};