class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n,0), r(n,0);
        int water = 0;
        for(int i=0; i<n; i++)
        {
            water = max(water,height[i]);
            l[i] = water;
        }
        water = 0;
        for(int i=n-1; i>=0; i--)
        {
            water = max(water,height[i]);
            r[i] = water;
        }
        water = 0;
        for(int i=0; i<n; i++)
        {
            water += min(l[i],r[i]) - height[i];
        }
        return water;
    }
};