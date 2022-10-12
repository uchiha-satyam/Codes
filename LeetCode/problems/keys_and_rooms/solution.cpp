class Solution {
public:

    void bfs(vector<vector<int>>& rooms, vector<bool>& visited, int s)
    {
        if(visited[s]) return;
        visited[s] = true;
        for(int i=0; i<rooms[s].size(); i++)
        {
            bfs(rooms,visited,rooms[s][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int count = 0;
        vector<bool> visited(n,false);
        bfs(rooms,visited,0);
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false) return false;
        }
        return true;
    }
};