class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos = -1;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]*nums[i+1]<=0)
            {
                pos = i+1;
                break;
            }
        }
        int l=pos-1, r=pos;
        if(pos==-1)
        {
            if(nums[0]>0)
            {
                l=-1;
                r=0;
            }
            else
            {
                l=nums.size()-1;
                r=nums.size();
            }
        }
        vector<int> vec;
        while(l>=0&&r<nums.size())
        {
            int lv = nums[l]*nums[l];
            int rv = nums[r]*nums[r];
            if(lv==rv)
            {
                vec.push_back(lv);
                vec.push_back(lv);
                l--;
                r++;
            }
            else if(lv<rv)
            {
                vec.push_back(lv);
                l--;
            }
            else
            {
                vec.push_back(rv);
                r++;
            }
        }
        while(l>=0)
        {
            vec.push_back(nums[l]*nums[l]);
            l--;
        }
        while(r<nums.size())
        {
            vec.push_back(nums[r]*nums[r]);
            r++;
        }
        return vec;
    }
};