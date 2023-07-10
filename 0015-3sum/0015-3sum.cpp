class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            if(i!=0&&nums[i]==nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l<r)
            {
                int s = nums[l] + nums[r] + nums[i];
                if(s==0)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<n-1&&nums[l+1]==nums[l]) l++;
                    while(r>0&&nums[r-1]==nums[r]) r--;
                    l++;
                    r--;
                }
                else if(s<0)
                {
                    while(l<n-1&&nums[l+1]==nums[l]) l++;
                    l++;
                }
                else
                {
                    while(r>0&&nums[r-1]==nums[r]) r--;
                    r--;
                }
            }
        }
        return ans;
    }
};