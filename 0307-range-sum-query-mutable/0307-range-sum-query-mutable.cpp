class NumArray {
public:
    int size;
    vector<long long> sums;

    void build(vector<int>& nums, int x, int lx, int rx)
    {
        if(lx==rx)
        {
            if(lx<size) sums[x] = nums[lx];
            return;
        }
        int mx = lx + (rx-lx)/2;
        build(nums,2*x+1,lx,mx);
        build(nums,2*x+2,mx+1,rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    NumArray(vector<int>& nums) {
        size = 1;
        int n = nums.size();
        while(size<n) size *= 2;
        sums.resize(2*size,0LL);
        build(nums,0,0,size-1);
        // for(int i=0; i<nums.size(); i++)
        // update(i,nums[i]);
    }
    
    void update(int& i, int& val, int x, int lx, int rx)
    {
        if(lx==rx)
        {
            sums[x] = val;
            return;
        }
        int mx = lx + (rx-lx)/2;
        if(i<=mx) update(i,val,2*x+1,lx,mx);
        else update(i,val,2*x+2,mx+1,rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void update(int index, int val) {
        update(index,val,0,0,size-1);
    }
    
    void sumRange(int& l, int& r, int x, int lx, int rx, int& ans)
    {
        if(rx<l||lx>r) return;
        if(lx>=l&&rx<=r)
        {
            ans += sums[x];
            return;
        }
        int mx = lx + (rx-lx)/2;
        sumRange(l,r,2*x+1,lx,mx,ans);
        sumRange(l,r,2*x+2,mx+1,rx,ans);
    }

    int sumRange(int left, int right) {
        int ans = 0;
        sumRange(left,right,0,0,size-1,ans);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */