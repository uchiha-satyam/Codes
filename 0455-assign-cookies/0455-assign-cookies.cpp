class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int> mst;
        for(auto& x : s)
            mst.insert(x);
        int ans = 0;
        for(auto& x : g)
        {
            if(mst.lower_bound(x)!=mst.end())
            {
                ans++;
                mst.erase(mst.lower_bound(x));
            }
        }
        return ans;
    }
};