class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> arr1(n,0), arr2(n,0);
        int m1 = INT_MIN, m2 = INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            int a = values[i] - i;
            m2 = max(m2,a);
            arr2[i] = m2;
            arr1[i] = values[i] + i;
        }
        for(int i=0; i<n-1; i++)
        {
            m1 = max(m1,arr1[i]+arr2[i+1]);
        }
        return m1;
    }
};