class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int s1, s2, s3;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>=2; i--)
        {
            s1 = nums[i];
            s2 = nums[i-1];
            s3 = nums[i-2];
            if(s1<s2+s3 && s2<s1+s3 && s3<s1+s2 && s3>0)
            break;
            else s3=0;
        }
        if(s3>0) return s1+s2+s3;
        return s3;
    }
};