class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> inDegree(n,true);
        for(int i=0; i<edges.size(); i++)
        {
            inDegree[edges[i][1]] = false;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(inDegree[i])
            ans.push_back(i);
        }
        return ans;
    }
};