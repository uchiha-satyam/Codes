class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> arr(n,0);
        int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(prices[i]>ans)
            {
                ans = prices[i];
            }
            arr[i] = ans;
        }
        ans = 0;
        for(int i=0; i<n-1; i++)
        {
            if(arr[i+1]-prices[i]>ans)
            {
                ans = arr[i+1] - prices[i];
            }
        }
        return ans;
    }
};