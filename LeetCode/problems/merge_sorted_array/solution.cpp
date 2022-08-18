class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0, r=0;
        while(r<n)
        {
            if(l-r<m)
            {
                if(nums1[l]<=nums2[r])
                {
                    l++;
                }
                else
                {
                    nums1.insert(nums1.begin()+l,nums2[r]);
                    nums1.pop_back();
                    r++;
                }
            }
            else
            {
                nums1.insert(nums1.begin()+l,nums2[r]);
                nums1.pop_back();
                l++;
                r++;
            }
        }
    }
};