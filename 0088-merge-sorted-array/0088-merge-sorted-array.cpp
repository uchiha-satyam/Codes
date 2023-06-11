class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t = nums1;
        int p1=0, p2=0;
        for(int i=0; i<m+n; i++)
        {
            if(p1<m&&p2<n)
            {
                if(t[p1]<=nums2[p2])
                {
                    nums1[i] = t[p1];
                    p1++;
                }
                else
                {
                    nums1[i] = nums2[p2];
                    p2++;
                }
            }
            else if(p1<m)
            {
                nums1[i] = t[p1];
                p1++;
            }
            else if(p2<n)
            {
                nums1[i] = nums2[p2];
                p2++;
            }
        }
    }
};