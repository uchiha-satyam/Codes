class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int c = 0, m = 0, n = flips.size();
        for(int i=0; i<n; i++)
        {
            m = max(m,flips[i]);
            if(m==i+1) c++;
        }
        return c;
    }
};