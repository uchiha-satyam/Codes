class Solution {
private:
    void help(vector<vector<int>>& ad, int s, int val, vector<int>& ans)
    {
        if(ans[s]!=-1) return;
        ans[s] = val;
        for(int i=0; i<ad[s].size(); i++)
        {
            help(ad,ad[s][i],val,ans);
        }
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> ad(n);
        vector<int> ans(n,-1);
        vector<pair<int,int>> quietSorted(n);
        for(int i=0; i<n; i++)
        {
            quietSorted[i].first = quiet[i];
            quietSorted[i].second = i;
            // ans[i] = i;
        }
        for(int i=0; i<richer.size(); i++)
        {
            ad[richer[i][0]].push_back(richer[i][1]);
        }
        sort(quietSorted.begin(), quietSorted.end());
        for(int i=0; i<n; i++)
        {
            help(ad,quietSorted[i].second,quietSorted[i].second,ans);
        }
        return ans;
    }
};