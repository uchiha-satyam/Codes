class Solution {
public:

    bool path(int n, set<pair<int,int>>& ad, int s, int d, vector<bool>& visited)
    {
        int flag = (ad.count(make_pair(s,d)) || ad.count(make_pair(d,s)));
        for(int i=0; i<n && flag==false; i++)
        {
            if((ad.count(make_pair(s,i)) || ad.count(make_pair(i,s))) && visited[i]==false)
            {
                visited[i] = true;
                flag = path(n,ad,i,d,visited);
            }
        }
        return flag;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        set<pair<int,int>> ad;
        // vector<vector<bool>> ad(n,vector<bool>(n,false));
        vector<bool> visited(n,false);
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            ad.insert(make_pair(u,v));
            // ad[edges[i][0]][edges[i][1]] = ad[edges[i][1]][edges[i][0]] = true;
        }
        return path(n,ad,source,destination,visited);
    }
};