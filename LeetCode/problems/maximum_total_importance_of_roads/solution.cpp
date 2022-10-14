class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n,0);
        for(int i=0; i<roads.size(); i++)
        {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        sort(degree.begin(),degree.end());
        long long sum = 0;
        for(long long i=1; i<=n; i++)
        {
            sum += i * degree[i-1];
        }
        return sum;
    }
};