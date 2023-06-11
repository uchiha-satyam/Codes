class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        int p=0;
        for(auto& x : m)
        {
            if(x.second>=2)
            {
                nums[p] = x.first;
                p++;
            }
            nums[p] = x.first;
            p++;
        }
        return p;
    }
};