class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ad1(n);
        vector<vector<int>> ad2(n);
        for(int i=0; i<connections.size(); i++)
        {
            ad1[connections[i][0]].push_back(connections[i][1]);
            ad2[connections[i][1]].push_back(connections[i][0]);
        }
        int count = 0;
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int s = q.front();
            visited[s] = true;
            q.pop();
            for(int i=0; i<ad1[s].size(); i++)
            {
                if(!visited[ad1[s][i]])
                {
                    count++;
                    q.push(ad1[s][i]);
                }
            }
            for(int i=0; i<ad2[s].size(); i++)
            {
                if(!visited[ad2[s][i]])
                q.push(ad2[s][i]);
            }
        }
        return count;
    }
};