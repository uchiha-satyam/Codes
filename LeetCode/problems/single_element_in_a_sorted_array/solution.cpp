class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        while(s!=e)
        {
            int m = s + (e-s)/2;
            if(nums[m-1]==nums[m])
            {
                m++;
            }
            if(m%2)
            {
                e = m-1;
            }
            else
            {
                s = m;
            }
            // cout<<s<<" "<<e<<endl;
        }
        return nums[s];
    }
};