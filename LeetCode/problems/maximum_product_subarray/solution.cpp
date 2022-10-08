class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = 1, maxProduct = INT_MIN, rest = 1;
        for(int i=0; i<n; i++)
        {
            product *= nums[i];
            maxProduct = max(maxProduct,product);
            if(product==0)
            {
                product = 1;
                rest = 1;
                continue;
            }
            if(product<0)
            {
                product *= rest;
                if(product>0)
                {
                    maxProduct = max(maxProduct,product);
                    rest = 1;
                    continue;
                }
                rest = product;
                product = 1;
            }
        }
        product = 1;
        rest = 1;
        for(int i=n-1; i>=0; i--)
        {
            product *= nums[i];
            maxProduct = max(maxProduct,product);
            if(product==0)
            {
                product = 1;
                rest = 1;
                continue;
            }
            if(product<0)
            {
                product *= rest;
                if(product>0)
                {
                    maxProduct = max(maxProduct,product);
                    rest = 1;
                    continue;
                }
                rest = product;
                product = 1;
            }
        }
        return maxProduct;
    }
};