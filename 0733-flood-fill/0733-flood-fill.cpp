class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int moves[4][2] = {
            {0,1},
            {0,-1},
            {-1,0},
            {1,0}
        };
        int oc = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            if(image[p.first][p.second]==oc)
            {
                image[p.first][p.second] = color;
                for(int i=0; i<4; i++)
                {
                    int nr = p.first + moves[i][0];
                    int nc = p.second + moves[i][1];
                    if(nr>=0&&nr<image.size()&&nc>=0&&nc<image[0].size()&&image[nr][nc]!=color)
                        q.push({nr,nc});
                }
            }
        }
        return image;
    }
};