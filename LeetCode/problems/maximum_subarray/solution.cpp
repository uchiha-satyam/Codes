class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, msum=INT_MIN;
        bool flag=false;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>=0)
            {
                sum+=nums[i];
                flag = true;
                msum = max(sum,msum);
            }
            else
            {
                if(flag)
                msum=max(msum,sum);
                sum+=nums[i];
                if(sum<=0)
                {
                    msum=max(msum,sum);
                    sum=0;
                    flag = false;
                }
            }
            // cout<<sum<<"->"<<msum<<' ';
        }
        return msum;
    }
};