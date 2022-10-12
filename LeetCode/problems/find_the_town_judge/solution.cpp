class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<bool>> ad(n,vector<bool>(n,0));
        vector<bool> couldBeJudge(n,true);
        for(int i=0; i<trust.size(); i++)
        {
            ad[trust[i][0]-1][trust[i][1]-1] = true;
            couldBeJudge[trust[i][0]-1] = false;
        }
        int x = -1;
        for(int i=0; i<n; i++)
        {
            if(couldBeJudge[i])
            {
                x = i+1;
                for(int j=0; j<n; j++)
                {
                    if((j!=i && ad[j][i]==false) || (j==i && ad[j][i]==true))
                    {
                        x = -1;
                        break;
                    }
                }
                if(x!=-1) break;
            }
        }
        return x;
    }
};