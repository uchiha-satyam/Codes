class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> l(nums.size()), r(nums.size());
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            l[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=nums.size()-1; i>=0; i--)
        {
            r[i]=sum;
            sum+=nums[i];
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(l[i]==r[i]) return i;
        }
        return -1;
    }
};