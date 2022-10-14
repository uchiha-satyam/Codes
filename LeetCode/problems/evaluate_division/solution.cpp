class Solution {
public:

    bool help(unordered_map<string,vector<string>>& ad,map<pair<string,string>,double>& edge,unordered_set<string>& visited,string s,string d,double& ans)
    {
        visited.insert(s);
        if(edge.count(make_pair(s,d)))
        {
            ans *= edge[make_pair(s,d)];
            return true;
        }
        double backup = ans;
        for(int i=0; i<ad[s].size(); i++)
        {
            if(visited.count(ad[s][i])==0)
            {
                ans *= edge[make_pair(s,ad[s][i])];
                bool flag = help(ad,edge,visited,ad[s][i],d,ans);
                if(flag) return true;
                else ans = backup;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<string>> ad;
        map<pair<string,string>,double> edge;
        for(int i=0; i<equations.size(); i++)
        {
            ad[equations[i][0]].push_back(equations[i][1]);
            ad[equations[i][1]].push_back(equations[i][0]);
            edge[make_pair(equations[i][0],equations[i][1])] = values[i];
            edge[make_pair(equations[i][1],equations[i][0])] = (1.00/values[i]);
        }
        vector<double> ans(queries.size(),-1.00);
        for(int i=0; i<queries.size(); i++)
        {
            string s = queries[i][0];
            string d = queries[i][1];
            unordered_set<string> visited;
            if(ad.count(s)==0 || ad.count(d)==0) continue;
            if(s==d)
            {
                ans[i] = 1.00;
                continue;
            }
            double a = 1;
            bool flag = help(ad,edge,visited,s,d,a);
            if(flag) ans[i] = a;
        }
        return ans;
    }
};