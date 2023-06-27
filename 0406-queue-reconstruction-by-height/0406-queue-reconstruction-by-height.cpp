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
        for(auto& x : st)
        {
            if(x.first!=prev)
            {
                prev = x.first;
                sort(v.begin(),v.end());
            }
            people[v[x.second]] = {x.first,x.second};
            v[x.second] = INT_MAX;
        }
        return people;
    }
};