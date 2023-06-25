class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++)
            vp.push_back(make_pair(height[i],i));
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        int l = vp[0].second, r = vp[0].second, ans = 0;
        for(int i=1; i<n; i++)
        {
            ans = max(ans,vp[i].first * max(abs(vp[i].second - l),abs(vp[i].second - r)));
            l = min(l,vp[i].second);
            r = max(r,vp[i].second);
        }
        return ans;
    }
};