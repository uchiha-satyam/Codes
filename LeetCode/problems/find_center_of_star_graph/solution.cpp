class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_set<int> nodes;
        for(int i=0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(nodes.count(u)) return u;
            else nodes.insert(u);
            if(nodes.count(v)) return v;
            else nodes.insert(v);
        }
        return -1;
    }
};