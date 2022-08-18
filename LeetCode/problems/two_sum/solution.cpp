class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        vector<int> sol(2);
        int l=0, r=nums.size()-1;
        while(l<r)
        {
            int s = nums[l] + nums[r];
            if(s==target)
            {
                sol[0] = m[nums[l]].front();
                sol[1] = m[nums[r]].back();
                break;
            }
            else if(s<target)
                l++;
            else
                r--;
        }
        return sol;
    }
};