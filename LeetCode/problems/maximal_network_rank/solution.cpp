class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> net(n,make_pair(0,0));
        for(int i=0; i<n; i++)
        {
            net[i].second = i;
        }
        set<pair<int,int>> st;
        for(int i=0; i<roads.size(); i++)
        {
            // cout<<roads[i][0]<<" "<<roads[i][1]<<endl;
            st.insert(make_pair(roads[i][0],roads[i][1]));
            st.insert(make_pair(roads[i][1],roads[i][0]));
            net[roads[i][0]].first++;
            net[roads[i][1]].first++;
        }
        int maxNetworkRank = 0;
        int rank;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                rank = net[i].first + net[j].first - (st.count(make_pair(net[i].second,net[j].second)));
                maxNetworkRank = max(maxNetworkRank,rank);
            }
        }
        return maxNetworkRank;
    }
};