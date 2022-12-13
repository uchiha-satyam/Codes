class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_set<unsigned long> data;
        for(int i=0; i<n; i++)
            data.insert(nums[i]);
        sort(nums.begin(),nums.end());
        int m_count = 0;
        for(int i=0; i<n; i++)
        {
            int count = 0;
            unsigned long l = nums[i];
            while(data.count(l))
            {
                count++;
                l = l*l;
            }
            m_count = max(m_count,count);
        }
        if(m_count<2) return -1;
        else return m_count;
    }
};