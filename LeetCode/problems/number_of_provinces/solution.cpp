class Solution {
public:

    void miniHelp(vector<vector<int>>& isConnected, vector<bool>& visited, int s)
    {
        if(visited[s]) return;
        visited[s] = true;
        for(int i=0; i<visited.size(); i++)
        {
            if(isConnected[s][i])
            miniHelp(isConnected,visited,i);
        }
    }

    int help(vector<vector<int>>& isConnected, vector<bool>& visited)
    {
        int count = 0;
        for(int i=0; i<visited.size(); i++)
        {
            if(!visited[i])
            {
                count++;
                miniHelp(isConnected,visited,i);
            }
        }
        return count;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        return help(isConnected,visited);
    }
};