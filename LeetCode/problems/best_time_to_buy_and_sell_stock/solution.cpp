class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> m(prices.size()-1);
        int ma = 0;
        for(int i=prices.size()-2; i>=0; i--)
        {
            m[i] = max(ma,prices[i+1]);
            ma = m[i];
        }
        ma=0;
        for(int i=0; i<m.size(); i++)
        {
            ma = max(ma,m[i]-prices[i]);
        }
        return ma;
    }
};