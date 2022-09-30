class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+2);
        dp[0].push_back(1);
        dp[1].push_back(1);
        dp[1].push_back(1);
        for(int i=2; i<=rowIndex; i++)
        {
            // for(auto &x : dp)
            // {
            //     for(auto &y : x)
            //     cout<<y<<" ";
            //     cout<<endl;
            // }
            dp.erase(dp.begin());
            for(int j=0; j<=i; j++)
            {
                if(j==0||j==i) dp[1].push_back(1);
                else dp[1].push_back(dp[0][j-1]+dp[0][j]);
            }
        }
        return (rowIndex==0) ? dp[0] : dp[1];
    }
};