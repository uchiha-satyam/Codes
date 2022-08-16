class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> pos;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0) pos.push(i);
            else
            {
                if(pos.size())
                {
                    int p=pos.front();
                    pos.pop();
                    swap(nums[i],nums[p]);
                    pos.push(i);
                }
            }
        }
    }
};