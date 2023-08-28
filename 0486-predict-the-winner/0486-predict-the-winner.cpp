class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<pair<int,int>,bool>>> dp(n,vector<pair<pair<int,int>,bool>>(n,{{0,0},false}));
        for(int l=n-1; l>=0; l--)
        {
            for(int r=l; r<n; r++)
            {
                if(l==r)
                {
                    dp[l][r] = {{nums[l],0},true};
                    continue;
                }
                int val1 = nums[l] + dp[l+1][r].first.second;
                int val2 = nums[r] + dp[l][r-1].first.second;
                bool b1 = val1 >= dp[l+1][r].first.first;
                bool b2 = val2 >= dp[l][r-1].first.first;
                if((b1&&b2&&val1>=val2)||(!b2&&b1))
                    dp[l][r] = {{val1,dp[l+1][r].first.first},true};
                else if((b1&&b2&&val1<val2)||(!b1&&b2))
                    dp[l][r] = {{val2,dp[l][r-1].first.first},true};
                if(!b1&&!b2)
                {
                    if(val1>=val2)
                        dp[l][r] = dp[l][r] = {{val1,dp[l+1][r].first.first},false};
                    else
                        dp[l][r] = {{val2,dp[l][r-1].first.first},false};
                }
            }
        }
        return dp[0][n-1].second;
    }
};