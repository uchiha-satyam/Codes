class Solution {
public:

    int calc(int count)
    {
        if(count<3) return 0;
        int ans = 0;
        for(int i=3; i<=count; i++)
        {
            ans += count - i + 1;
        }
        return ans;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        vector<int> diff(n-1,0);
        for(int i=0; i<n-1; i++)
        diff[i] = nums[i+1]-nums[i];
        int prev = diff[0];
        int count = 0;
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            if(diff[i]==prev)
            {
                count++;
            }
            else
            {
                ans += calc(count+1);
                count = 1;
                prev = diff[i];
            }
        }
        ans += calc(count+1);
        // cout<<count;
        return ans;
    }
};