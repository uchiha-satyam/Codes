class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> ad(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][0]]++;
            ad[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> completed;
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]==0) completed.push(i);
        }
        while(!completed.empty())
        {
            int c = completed.front();
            completed.pop();
            for(int j=0; j<ad[c].size(); j++)
            {
                inDegree[ad[c][j]]--;
                if(inDegree[ad[c][j]]==0) completed.push(ad[c][j]);
            }
        }
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]) return false;
        }
        return true;
    }
};