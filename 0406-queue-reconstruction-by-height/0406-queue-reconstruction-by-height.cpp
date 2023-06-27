class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        set<pair<int,int>> st;
        int n = people.size();
        for(int i=0; i<n; i++)
            st.insert(make_pair(people[i][0],people[i][1]));
        int prev = 0;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            v[i] = i;
        vector<int> remove;
        for(auto& x : st)
        {
            if(x.first!=prev)
            {
                prev = x.first;
                int err = 0;
                for(auto& t : remove)
                {
                    v.erase(v.begin() + t - err);
                    err++;
                }
                remove.clear();
            }
            people[v[x.second]] = {x.first,x.second};
            remove.push_back(x.second);
        }
        return people;
    }
};