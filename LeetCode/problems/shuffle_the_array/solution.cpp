class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n);
        for(int i=0; i<2*n; i++)
        {
            if(i%2)
            {
                v[i] = nums[n + (i-1)/2];
            }
            else
            {
                v[i] = nums[i/2];
            }
        }
        return v;
    }
};