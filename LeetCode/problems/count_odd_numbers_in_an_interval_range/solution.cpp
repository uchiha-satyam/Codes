class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high-low)/2;
        if(low%2||high%2) ans += 1;
        return ans;
    }
};