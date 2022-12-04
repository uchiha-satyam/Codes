class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0), ans;
        vector<vector<int>> ad(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][0]]++;
            ad[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> available;
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]==0) available.push(i);
        }
        while(!available.empty())
        {
            int c = available.front();
            for(int i=0; i<ad[c].size(); i++)
            {
                inDegree[ad[c][i]]--;
                if(inDegree[ad[c][i]]==0) available.push(ad[c][i]);
            }
            ans.push_back(c);
            available.pop();
        }
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i])
            {
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};