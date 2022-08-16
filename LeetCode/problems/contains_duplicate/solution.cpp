class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i=0; i<nums.size(); i++)
        {
            if(m.count(nums[i])) return true;
            else m.insert(make_pair(nums[i],true));
        }
        return false;
    }
};